#include "GameplayTags/MVVTags.h"

// Namespaces are used like a filing system, a series of containers to organize my tags in, in this case.
namespace MVVTags
{
	namespace MVVAbilities
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(ActivateOnGiven, "MVVTags.MVVAbilities.ActivateOnGiven", "Tag for Abilities that should activate immediately once given.")

		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Primary, "MVVTags.MVVAbilities.Primary", "Tag for the Primary Ability")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Secondary, "MVVTags.MVVAbilities.Secondary", "Tag for the Secondary Ability")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Tertiary, "MVVTags.MVVAbilities.Tertiary", "Tag for the Tertiary Ability")
	}
	
	namespace Events
	{
		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(HitReact, "MVVTags.Events.Enemy.HitReact", "Tag for the enemy HitReact Event.")
		}
	}
}