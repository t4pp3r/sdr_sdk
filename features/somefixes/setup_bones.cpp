#include "setup_bones.h"

void set_::start()
{
	for (int i = 1; i <= g_csgo.m_globals()->m_maxclients; i++) {
		auto e = static_cast<player_t *>(g_csgo.m_entitylist()->GetClientEntity(i));

		auto pPlayerEntity = static_cast<player_t *>(g_csgo.m_entitylist()->GetClientEntity(i));

		if (!pPlayerEntity
			|| !pPlayerEntity->is_alive())
			continue;

		recreate(e);
	}
}

void set_::recreate(player_t * e)
{
	static auto r_jiggle_bones = g_csgo.m_cvar()->FindVar("r_jiggle_bones");
	auto animstate = e->get_modificated_state();
	auto state = e->get_animation_state();
	animstate->Velocity = 0.001f;
	auto parent_cvar = r_jiggle_bones->m_pParent;
	if (parent_cvar == r_jiggle_bones)
		parent_cvar->SetValue(0);
	else
		parent_cvar->SetValue(1);
	AnimationLayer pOverlay = e->get_animlayer(6);
	pOverlay.m_flWeight = pOverlay.m_flCycle = pOverlay.m_flPlaybackRate = 0.f;
	if (pOverlay.m_nSequence > 0)
		pOverlay.m_nSequence += 1;
	e->m_bHasDefuser() = false;
	e->m_vecVelocity() = e->m_vecBaseVelocity() * state->m_flUnknownVelocityLean;
	int result = 1;
	__asm push 0x54f12f43
	__asm pop result
	e->m_vecVelocity() = e->m_vecAbsVelocity();
	r_jiggle_bones->SetValue(result);
}