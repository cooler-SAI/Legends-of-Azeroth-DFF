/*
 * Copyright 2023 AzgathCore
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "emerald_nightmare.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "AreaTriggerTemplate.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_FORCES_OF_NIGHTMARE_EMOTE = 1,
    SAY_FORCES_OF_NIGHTMARE = 2,
    SAY_NIGHTMARE_BRAMBLES = 3,
    SAY_DEATH = 6,
};

enum Spells
{
    //Phase 1
    SPELL_CREEPING_NIGHTMARES = 210280,
    SPELL_FORCES_OF_NIGHTMARE = 212726,
    SPELL_NIGHTMARE_BRAMBLES_SUM = 210290,
    SPELL_AURA_OF_DREAD_THORNS = 210346,
    SPELL_SUM_ENTANGLING_NIGHTMARES = 214454,

    //Phase 2
    SPELL_OVERWHELMING_NIGHTMARE = 217368, //?
    SPELL_NIGHTMARE_BLAST_SAVER = 214706,
    SPELL_SPEAR_OF_NIGHTMARES = 214529,
    SPELL_NIGHTMARES_AT = 214711, //Dmg 214712

    //Mythic
    SPELL_NIGHTMARE_BLAST = 213162,
    SPELL_BEASTS_OF_NIGHTMARE = 214876,

    //Trash
        //Malfurion Stormrage - 106482
        SPELL_CLEANSING_GROUND_FILTER = 212630,
        SPELL_CLEANSING_GROUND_AT = 212639,
        SPELL_CLEANSING_GROUND_STAGE_2 = 214249,
        SPELL_STORMS_RAGE = 214713,

        //Nightmare Sapling - 106427
        SPELL_GERMINATING = 210861,
        SPELL_NIGHTMARE_GERMINATE = 210974,
        SPELL_ALLIES_GERMINATE = 212175,

        //Tormented Souls - 106895
        SPELL_TORMENTED = 212178,
        SPELL_WISPS_VISUAL_CORRUPTED = 212466,
        SPELL_WISPS_VISUAL_ALLIES = 212467,
        SPELL_SUM_NIGHTMARE_WISPS = 212188,
        SPELL_SUM_ALLIES_WISPS = 212192,

        //Corrupted Emerald Egg - 106898
        SPELL_INCUBATING = 212231,
        SPELL_SUM_NIGHTMARE_DRAKE = 212233,
        SPELL_SUM_ALLIES_DRAKE = 212235,

        //Corrupted Nature - 106899
        SPELL_DRYAD_DUMMY = 212241,
        SPELL_DRYAD_VISUAL = 212424,
        SPELL_SUM_NIGHTMARE_DRYAD = 212242,
        SPELL_SUM_ALLIES_DRYAD = 212243,

        //ALLIES_WISP - 106659
        SPELL_CLEANSING_DETONATE_VIS = 213403,
        SPELL_CLEANSING_DETONATE_AT = 211878,

        //CLEANSED_ANCIENT - 106667
        SPELL_NATURES_FURY = 215099,
        SPELL_REPLENISHING_ROOTS = 211619,

        //EMERALD_DRAKE - 106809
        SPELL_ANCIENT_DREAM_FILTER = 211935,
        SPELL_POISON_BLAST = 216510,

        //REDEEMED_SISTER - 106831
        SPELL_UNBOUND_TOUCH_FILTER = 211976,
        SPELL_JAVELIN_TOSS = 215106,

        //CORRUPTED_WISP - 106304
        SPELL_DESTRUCTIVE_NIGHTMARES = 210617,
        SPELL_DESTRUCTIVE_NIGHTMARES_DMG = 210619,
        SPELL_CORRUPTED_DETONATE = 226713, //Mythic

        //NIGHTMARE_ANCIENT - 105468
        SPELL_DESICCATING_STOMP_DUMMY = 226816,
        SPELL_DESICCATING_STOMP = 211073,
        SPELL_DESICCATING_STOMP_MYTHIC = 226821, //Mythic
        SPELL_DESICCATION = 211156,

        //ROTTEN_DRAKE - 105494
        SPELL_ROTTEN_BREATH_FILTER = 211189,
        SPELL_ROTTEN_BREATH_SUM_TRIGGER = 211188,
        SPELL_ROTTEN_BREATH_DMG = 211192,
        SPELL_NIGHTMARE_BUFFET = 211180,

        //NPC_TWISTED_SISTER - 105495
        SPELL_NIGHTMARE_JAVELIN = 211498,
        SPELL_TWISTED_TOUCH_OF_LIFE_FILTER = 211462,
        SPELL_SCORNED_TOUCH_FILTER = 211487,

        //NIGHTMARE_BRAMBLES - 106167
        SPELL_NIGHTMARE_BRAMBLES_AT = 210331,
        SPELL_NIGHTMARE_BRAMBLES_AT_PER = 210312,
        SPELL_NIGHTMARE_BRAMBLES_UNKNOWN = 210316, //?

        //ENTANGLING_ROOTS - 108040
        SPELL_ENTANGLING_NIGHTMARES_VIS = 214460,
        SPELL_ENTANGLING_NIGHTMARES_AURA = 214463,
        SPELL_ENTANGLING_NIGHTMARES_VEH = 214462,
        SPELL_ENTANGLING_NIGHTMARES_STUN = 214505,

        //BEAST_OF_NIGHTMARE - 108208
        SPELL_GRIPPING_FOG_AT = 214878,

        //Other
        SPELL_NIGHTMARE_DISSOLVE_IN = 212461,
        SPELL_NIGHTMARE_DISSOLVE_OUT = 212563,
        SPELL_DUDE_TRACKER_AT = 212622,
        SPELL_SUMMON_DRAKES_DUMMY = 212604,
        SPELL_CLEANSED_GROUND = 212170,
        SPELL_CAST_HELPFUL_SPELL = 211639,
        SPELL_CLEANSED_DISSOLVE_OUT = 212562,
        SPELL_DISSOLVE_CLEANSED_IN = 210988,
        SPELL_NIGHTMARE_ENERGY = 224200,
        SPELL_COSMETIC_CHANNEL = 225782,
};

enum eEvents
{
    EVENT_FORCES_OF_NIGHTMARE = 1,
    EVENT_NIGHTMARE_BRAMBLES = 2,
    EVENT_OVERWHELMING_NIGHTMARE = 3,
    EVENT_NIGHTMARE_BLAST_SAVER = 4,
    EVENT_SPEAR_OF_NIGHTMARES = 5,
    EVENT_CHECH_EVADE = 6,
    EVENT_NIGHTMARE_BLAST_OR_BEAST = 7, //Mythic

    EVENT_SCENE,

    EVENT_1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
    EVENT_5,
    EVENT_6,
    EVENT_7,
    EVENT_8,
    EVENT_9,
    EVENT_10
};

enum Acs
{
    ACTION_1 = 1,
    ACTION_2,
    ACTION_3,
    ACTION_4,
    ACTION_5,
};

enum eVisualKit
{
    BRAMBLES_KIT_1 = 67102, //SMSG_PLAY_SPELL_VISUAL_KIT
};

Position const forcesPos[4] =
{
    {11392.7f, -12723.7f, 487.0f},  //NPC_TORMENTED_SOULS
    {11339.5f, -12719.2f, 487.33f}, //NPC_NIGHTMARE_SAPLING
    {11340.0f, -12667.8f, 487.45f}, //NPC_CORRUPTED_NATURE
    {11391.2f, -12670.0f, 487.18f}, //NPC_CORRUPTED_EMERALD_EGG
};

Position const malfurionPos[1] =
{
    {11359.50f, -12665.90f, 487.30f, 4.79f}
};

Position const centrPos = { 11366.2f, -12695.1f, 486.91f };

Position const beastsPos[9] =
{
    {11408.86f, -12738.13f, 488.3f, 2.42f}, //+
    {11405.04f, -12698.67f, 488.0f, 3.06f},
    {11409.42f, -12661.88f, 488.0f, 3.74f}, //+
    {11375.43f, -12660.12f, 487.0f, 4.64f},
    {11354.59f, -12653.14f, 488.3f, 4.86f},
    {11331.45f, -12661.74f, 488.4f, 5.38f}, //+
    {11328.11f, -12700.74f, 487.4f, 0.06f},
    {11335.28f, -12734.77f, 488.0f, 0.97f},
    {11366.40f, -12742.10f, 488.2f, 1.64f}, //+
};

void AddSC_boss_cenarius()
{
    
}
