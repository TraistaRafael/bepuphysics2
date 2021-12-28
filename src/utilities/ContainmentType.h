#pragma once

namespace BepuUtilities
{
	enum ContainmentType
	{
		/// <summary>
		/// The objects are separate.
		/// </summary>
		Disjoint,
		/// <summary>
		/// One object fully contains the other.
		/// </summary>
		Contains,
		/// <summary>
		/// The objects are intersecting, but neither object fully contains the other.
		/// </summary>
		Intersects
	};
}
