﻿using BepuPhysics.CollisionDetection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace BepuPhysics.Collidables
{
    /// <summary>
    /// Defines how a collidable will handle collision detection in the presence of velocity.
    /// </summary>
    public enum ContinuousDetectionMode
    {
        /// <summary>
        /// <para>No sweep tests are performed. Default speculative contact generation will occur within the speculative margin.</para>
        /// <para>The collidable's bounding box will not be expanded by velocity beyond the speculative margin.</para>
        /// <para>This is the cheapest mode. If a Discrete mode collidable is moving quickly and the maximum speculative margin is limited,
        /// the fact that its bounding box is not expanded may cause it to miss a collision even with a non-Discrete collidable.</para>
        /// </summary>
        Discrete = 0,
        /// <summary>
        /// <para>No sweep tests are performed. Default speculative contact generation will occur within the speculative margin.</para>
        /// <para>The collidable's bounding box will be expanded by velocity without being limited by the speculative margin.</para>
        /// <para>This is useful when a collidable may move quickly and does not itself require continuous detection, but there exist other collidables with continuous modes 
        /// that should avoid missing collisions.</para>
        /// </summary>
        Passive = 1,
        /// <summary>
        /// <para>Collision detection will start with a sweep test to identify a likely time of impact. Speculative contacts will be generated for the predicted collision.</para>
        /// <para>This mode can capture angular motion with very few ghost collisions. It can, however, miss secondary collisions that would have occurred due to the primary impact's velocity change.</para>
        /// </summary>
        Continuous = 2,
    }

    /// <summary>
    /// Defines how a collidable handles collisions with significant velocity.
    /// </summary>
    public struct ContinuousDetection
    {
        /// <summary>
        /// The continuous collision detection mode.
        /// </summary>
        public ContinuousDetectionMode Mode;

        /// <summary>
        /// Lower bound on the value of the speculative margin used by the collidable.
        /// </summary>
        /// <remarks>0 tends to be a good default value. Higher values can be chosen if velocity magnitude is a poor proxy for speculative margins, but these cases are rare.
        /// In those cases, try to use the smallest value that still satisfies requirements to avoid creating unnecessary contact constraints.</remarks>
        public float MinimumSpeculativeMargin;

        /// <summary>
        /// Upper bound on the value of the speculative margin used by the collidable.
        /// </summary>
        /// <remarks><see cref="float.MaxValue"/> tends to be a good default value for discrete or passive mode collidables. 
        /// The speculative margin will increase in size proportional to velocity magnitude, so high values don't usually cause performance problems.
        /// <para>Smaller values are necessary when using continuous collision detection, since continuous collision detection will early out once it finds a time that puts the collidables within speculative margin.</para>
        /// </remarks>
        public float MaximumSpeculativeMargin;

        /// <summary>
        /// If using <see cref="ContinuousDetectionMode.Continuous"/>, this defines the minimum progress that the sweep test will make when searching for the first time of impact.
        /// Collisions lasting less than <see cref="MinimumSweepTimestep"/> may be missed by the sweep test. Using larger values can significantly increase the performance of sweep tests.
        /// </summary>
        public float MinimumSweepTimestep;

        /// <summary>
        /// If using <see cref="ContinuousDetectionMode.Continuous"/>, sweep tests will terminate if the time of impact region has been refined to be smaller than <see cref="SweepConvergenceThreshold"/>.
        /// Values closer to zero will converge more closely to the true time of impact, but for speculative contact generation larger values usually work fine.
        /// Larger values allow the sweep to terminate much earlier and can significantly improve sweep performance.
        /// </summary>
        public float SweepConvergenceThreshold;

        /// <summary>
        /// Gets whether the continuous collision detection configuration will permit bounding box expansion beyond the calculated speculative margin.
        /// </summary>
        public bool AllowExpansionBeyondSpeculativeMargin => (uint)Mode > 0;

        //Note: there's no "Discrete" property anymore. Discrete with default values of 0 and float.MaxValue would be fully equivalent to Passive with the same configuration, so better just to encourage the Passive property instead.

        /// <summary>
        /// <para>No sweep tests are performed. Default speculative contact generation will occur within the speculative margin.</para>
        /// <para>The collidable's bounding box will not be expanded by velocity beyond the speculative margin.</para>
        /// <para>This can be marginally cheaper than Passive modes if using a limited maximum speculative margin. If a Discrete mode collidable is moving quickly and the maximum speculative margin is limited,
        /// the fact that its bounding box is not expanded may cause it to miss a collision even with a non-Discrete collidable.</para>
        /// <para>Note that Discrete and Passive only differ if maximum speculative margin is restricted.</para>
        /// </summary>
        /// <param name="minimumSpeculativeMargin">Minimum speculative margin to use for the collidable. Zero is typically a good choice.</param>
        /// <param name="maximumSpeculativeMargin">Maximum speculative margin to use for the collidable.
        /// If using Discrete instead of Passive, this is presumably some smaller finite value to limit the number of collision pairs found during high velocity movement.</param>
        /// <returns>Detection settings for the given discrete configuration.</returns>
        public static ContinuousDetection Discrete(float minimumSpeculativeMargin = 0f, float maximumSpeculativeMargin = float.MaxValue)
        {
            return new() { Mode = ContinuousDetectionMode.Discrete, MinimumSpeculativeMargin = minimumSpeculativeMargin, MaximumSpeculativeMargin = maximumSpeculativeMargin };
        }

        /// <summary>
        /// <para>No sweep tests are performed. Default speculative contact generation will occur within the speculative margin.</para>
        /// <para>The collidable's bounding box and speculative margin will be expanded by velocity.</para>
        /// <para>This is useful when a collidable may move quickly and does not itself require continuous detection, but there exist other collidables with continuous modes that should avoid missing collisions.</para>
        /// </summary>
        /// <returns>Detection settings for the passive configuration.</returns>
        public static ContinuousDetection Passive
        {
            get { return new() { Mode = ContinuousDetectionMode.Passive, MinimumSpeculativeMargin = 0, MaximumSpeculativeMargin = float.MaxValue }; }
        }

        /// <summary>
        /// <para>No sweep tests are performed. Default speculative contact generation will occur within the speculative margin.</para>
        /// <para>The collidable's bounding box will be expanded by velocity. The speculative margin will grow with velocity but be bounded by the given interval.</para>
        /// <para>This is useful when a collidable may move quickly and does not itself require continuous detection, but there exist other collidables with continuous modes that should avoid missing collisions.</para>
        /// </summary>
        /// <param name="minimumSpeculativeMargin">Minimum speculative margin to use for the collidable. Zero is typically a good choice.</param>
        /// <param name="maximumSpeculativeMargin">Maximum speculative margin to use for the collidable.</param>
        /// <returns>Detection settings for the given passive configuration.</returns>
        public static ContinuousDetection CreatePassive(float minimumSpeculativeMargin, float maximumSpeculativeMargin)
        {
            return new() { Mode = ContinuousDetectionMode.Passive, MinimumSpeculativeMargin = minimumSpeculativeMargin, MaximumSpeculativeMargin = maximumSpeculativeMargin };
        }

        /// <summary>
        /// <para>Collision detection will start with a sweep test to identify a likely time of impact. Speculative contacts will be generated for the predicted collision.</para>
        /// <para>This mode can capture angular motion with very few ghost collisions. It can, however, miss secondary collisions that would have occurred due to the primary impact's velocity change.</para>
        /// </summary>
        /// <param name="minimumSweepTimestep">Minimum progress that the sweep test will make when searching for the first time of impact.
        /// Collisions lasting less than MinimumProgress may be missed by the sweep test. Using larger values can significantly increase the performance of sweep tests.</param>
        /// <param name="sweepConvergenceThreshold">Threshold against which the time of impact region is compared for sweep termination. 
        /// If the region has been refined to be smaller than SweepConvergenceThreshold, the sweep will terminate.
        /// Values closer to zero will converge more closely to the true time of impact, but for speculative contact generation larger values usually work fine.
        /// Larger values allow the sweep to terminate much earlier and can significantly improve sweep performance.</param>
        /// <param name="minimumSpeculativeMargin">Minimum speculative margin to use for the collidable. Zero is typically a good choice.</param>
        /// <param name="maximumSpeculativeMargin">Maximum speculative margin to use for the collidable.</param>
        /// <returns>Detection settings for the given continuous configuration.</returns>
        public static ContinuousDetection Continuous(float minimumSweepTimestep = 1e-3f, float sweepConvergenceThreshold = 1e-3f, float minimumSpeculativeMargin = 0f, float maximumSpeculativeMargin = float.MaxValue)
        {
            return new()
            {
                Mode = ContinuousDetectionMode.Continuous,
                MinimumSpeculativeMargin = minimumSpeculativeMargin,
                MaximumSpeculativeMargin = maximumSpeculativeMargin,
                MinimumSweepTimestep = minimumSweepTimestep,
                SweepConvergenceThreshold = sweepConvergenceThreshold
            };
        }
    }

    /// <summary>
    /// Description of a collidable instance living in the broad phase and able to generate collision pairs.
    /// Collidables with a ShapeIndex that points to nothing (a default constructed TypedIndex) do not actually refer to any existing Collidable.
    /// This can be used for a body which needs no collidable representation.
    /// </summary>
    public struct Collidable
    {
        /// <summary>
        /// Continuous collision detection settings for this collidable. Includes the collision detection mode to use and tuning variables associated with those modes.
        /// </summary>
        public ContinuousDetection Continuity;

        /// <summary>
        /// Index of the shape used by the body. While this can be changed, any transition from shapeless->shapeful or shapeful->shapeless must be reported to the broad phase. 
        /// If you need to perform such a transition, consider using <see cref="Bodies.SetShape"/> or <see cref="Bodies.ApplyDescription"/>; those functions update the relevant state.
        /// </summary>
        public TypedIndex Shape;

        /// <summary>
        /// Automatically computed size of the margin around the surface of the shape in which contacts can be generated. These contacts will have negative depth and only contribute if the frame's velocities
        /// would push the shapes of a pair into overlap. 
        /// <para>This is automatically set by bounding box prediction each frame, and is bound by the collidable's <see cref="ContinuousDetection.MinimumSpeculativeMargin"/> and <see cref="ContinuousDetection.MaximumSpeculativeMargin"/> values.
        /// The effective speculative margin for a collision pair can also be modified from <see cref="INarrowPhaseCallbacks"/> callbacks.</para>
        /// <para>This should be positive to avoid jittering.</para>
        /// <para>It can also be used as a form of continuous collision detection, but excessively high values combined with fast motion may result in visible 'ghost collision' artifacts. 
        /// For continuous collision detection with less chance of ghost collisions, use <see cref="ContinuousDetectionMode.Continuous"/>.</para>
        /// <para>If using <see cref="ContinuousDetectionMode.Continuous"/>, consider setting <see cref="ContinuousDetection.MaximumSpeculativeMargin"/> to a smaller value to help filter ghost collisions.</para>
        /// </summary>
        public float SpeculativeMargin;
        /// <summary>
        /// Index of the collidable in the broad phase. Used to look up the target location for bounding box scatters. Under normal circumstances, this should not be set externally.
        /// </summary>
        public int BroadPhaseIndex;

    }
}
