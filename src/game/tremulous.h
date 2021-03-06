/*
===========================================================================
Copyright (C) 1999-2005 Id Software, Inc.
Copyright (C) 2000-2006 Tim Angus

This file is part of Tremulous.

Tremulous is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

Tremulous is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Tremulous; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/


/*
 * ALIEN weapons
 *
 * _REPEAT  - time in msec until the weapon can be used again
 * _DMG     - amount of damage the weapon does
 *
 * ALIEN_WDMG_MODIFIER - overall damage modifier for coarse tuning
 *
 * Knockbacks are currently disabled for claws until i get a compiler working.
 */

#define ALIEN_WDMG_MODIFIER         1.0f
#define ADM(d)                      ((int)((float)d*ALIEN_WDMG_MODIFIER))
#define ALIENREGEN_NOCREEP_MOD      0.67f

#define ABUILDER_BUILD_REPEAT       500
#define ABUILDER_CLAW_DMG           ADM(26) //20) //still 3 hit kill with new armour system... (head mod = 1.8)
#define ABUILDER_CLAW_RANGE         78.0f //64f
#define ABUILDER_CLAW_WIDTH         15.0f //4f
#define ABUILDER_CLAW_REPEAT        900
#define ABUILDER_BASE_CLAW_REPEAT   1000
#define ABUILDER_CLAW_K_SCALE       0.0f
#define ABUILDER_BASE_DELAY         12000 //17000
#define ABUILDER_ADV_DELAY          10000 //12000 //8000->10000 to fix build timer vs build time of overmind

#define ABUILDER_BLOB_DMG           ADM(6)//4 -> 6
#define ABUILDER_BLOB_SPLASH_DMG    ADM(15)//Explosion damage //15
#define ABUILDER_BLOB_RADIUS        75     //explosion radius //75
#define ABUILDER_BLOB_REPEAT        1500 //500->800
#define ABUILDER_BLOB_SPEED         780.0f //800 -> 780 to match grenade
#define ABUILDER_BLOB_SPEED_MOD     0.6f
#define ABUILDER_BLOB_LIFETIME      ABUILDER_BLOB_REPEAT*3.5//Blob lifetime before exploding on its own; default is 5000 seconds, but you dont want a minefield of them because they get OP againts big guys
#define ABUILDER_BLOB_TIME          8000 //5000 how long a guy gets slowed down //5000 -> 8000
//Ripped from KoRx
//buildable regen = ABUILDER_BLOB_HEAL + ABUILDER_BLOB_HEAL_REGENMOD * buildable regen
#define ABUILDER_BLOB_HEAL          8
#define ABUILDER_BLOB_HEAL_REGENMOD 2.0f          

#define LEVEL0_BITE_DMG             ADM(36)
#define LEVEL0_BITE_RANGE           64.0f
#define LEVEL0_BITE_WIDTH           1.0f //6f
#define LEVEL0_BITE_REPEAT          333 //500 //333 makes stronger againts stationary camptards
#define LEVEL0_BITE_K_SCALE         1.0f
#define LEVEL0_SCRATCH_DMG          ADM(6 + (VAMP_ON * -3)) //dispite this, it is actually almost overpowered.
#define LEVEL0_SCRATCH_REPEAT       50 //Main pupous of this attack is to drain health slowly and gain it just like mara zap. //Changed to match dmg/s from normal bite on buildables //use 50 on vampire
#define LEVEL0_SCRATCH_RANGE        80
#define LEVEL0_SCRATCH_WIDTH        3

#define LEVEL1_CLAW_DMG             ADM(48)
#define LEVEL1_CLAW_RANGE           80.0f //96
#define LEVEL1_CLAW_WIDTH           10.0f
#define LEVEL1_CLAW_REPEAT          666
#define LEVEL1_CLAW_U_REPEAT        500
#define LEVEL1_CLAW_K_SCALE         0.0f //-1.0f brings enemy closer for a hug but comes with hardships of letting go of the human
#define LEVEL1_CLAW_U_K_SCALE       0.0f
#define LEVEL1_GRAB_RANGE           80.0f//64
#define LEVEL1_GRAB_TIME            300
#define LEVEL1_GRAB_U_TIME          450
#define LEVEL1_PCLOUD_DMG           ADM(8)
#define LEVEL1_PCLOUD_RANGE         200.0f //300 //limit troll gassers
#define LEVEL1_PCLOUD_REPEAT        1200 //2000 //adjust to visual animation
#define LEVEL1_PCLOUD_TIME          10000 //

#define LEVEL2_CLAW_DMG             ADM(42)
#define LEVEL2_CLAW_RANGE           128.0f //96 //longest range, since mar is glass cannon
#define LEVEL2_CLAW_WIDTH           14.0f //Normal mara is hard to use
#define LEVEL2_CLAW_U_WIDTH         12.0f //Counter for its high repeat rate
#define LEVEL2_CLAW_REPEAT          400 //normal marauder is still a glass cannon, just weaker in health.
#define LEVEL2_CLAW_K_SCALE         -2.0f//1
#define LEVEL2_CLAW_U_REPEAT        333 //Better glass cannon
#define LEVEL2_CLAW_U_K_SCALE       -2.0f//1

//Note: Full dmg depends on sv_fps
#define LEVEL2_AREAZAP_DMG          ADM(60) //use '60' when the zap width is large. Use '100' if the zap width is small. Be warned it gets overpowered.
#define LEVEL2_AREAZAP_RANGE        250.0f //360[lolards default] -> 250 since we now have sustain, no more long zaps
#define LEVEL2_AREAZAP_RANGE_SUSTAIN 400 //Range to allow sustaining the zap
#define LEVEL2_AREAZAP_WIDTH        1.0f //be able to zap humans in vents
#define LEVEL2_AREAZAP_REPEAT       750 //
#define LEVEL2_AREAZAP_TIME         3000 
#define LEVEL2_AREAZAP_MAX_TARGETS  7 //Helps zapping buildables
#define LEVEL2_WALLJUMP_MAXSPEED    90000.0f //1290.0f //idk, don't really want a max
#define LEVEL2_WALLJUMP_REPEAT      200 //time to jump again - default 200


//GPP style:
/*
#define LEVEL2_AREAZAP_DMG          ADM(60) //
#define LEVEL2_AREAZAP_RANGE        300.0f //360[lolards default] -> 300
#define LEVEL2_AREAZAP_WIDTH        1.0f //be able to zap humans in vents
#define LEVEL2_AREAZAP_REPEAT       750 //
#define LEVEL2_AREAZAP_TIME         1 
#define LEVEL2_AREAZAP_MAX_TARGETS  7 //Helps zapping buildables
#define LEVEL2_WALLJUMP_MAXSPEED    90000.0f
*/

//Goon modified heavily to get close to gpp values.
#define LEVEL3_CLAW_DMG             ADM(82)
#define LEVEL3_CLAW_RANGE           80.0f //96 //72 -> 80
#define LEVEL3_CLAW_WIDTH           12.0f //16f
#define LEVEL3_CLAW_REPEAT          700 //usually 700 //900 for gpp-related
#define LEVEL3_CLAW_K_SCALE         0.8f //0.4 //Was at 0.4 because it Might effect the pounce.
#define LEVEL3_CLAW_U_REPEAT        600 //usuaully 600 //800 ^^what i said
#define LEVEL3_CLAW_U_K_SCALE       0.8f
#define LEVEL3_POUNCE_DMG           ADM(115 + (VAMP_ON * 20)) //default 100 // Unvanquished play proves that 5 hit kills is still alright. Decreased from 180 -> 135 // -> 115 (bsuits take the same damage as laroured)
#define LEVEL3_POUNCE_RANGE         42.0f //default 72. Remember 0 is at the centre, it won't hit anything. Want 36, but can't hit because it still isn't long enough :( Gpp's value is probably 48, cause thats what it says in TremX's source code.// 48 -> 42
#define LEVEL3_POUNCE_WIDTH         27.0f //default 16. Also remember that the attacking stuff is in a form of a boundry box Any wider will cause it to hit the sides first. 32 for a more 'realistic' pounce so adv goons can get humans without aiming down. Works almost perfectly at this setting. It is basically the width of the goon/2. //32->28 because it hits stuff before you pounce-launch
#define LEVEL3_POUNCE_SPEED         700
#define LEVEL3_POUNCE_UPG_SPEED     800
#define LEVEL3_POUNCE_SPEED_MOD     0.75f
#define LEVEL3_POUNCE_CHARGE_TIME   700 
#define LEVEL3_POUNCE_TIME          400 //delay after touching ground?!? default 400
#define LEVEL3_BOUNCEBALL_DMG       ADM(136) //110 default

//I've added these to g_missile.c and bg_misc.c already for you.
#define LEVEL3_BOUNCEBALL_AMMO      3
#define LEVEL3_BOUNCEBALL_REPEAT    600 //default 1000 //deal with long range turrets quicker as a upside to the barb using player's inertia
#define LEVEL3_BOUNCEBALL_SPEED     1000.0f
#define LEVEL3_BOUNCEBALL_SPLASH_DMG  100 //Explosion dmg
#define LEVEL3_BOUNCEBALL_SPLASH_RADIUS 92 //Splash radius. Helps with sniping. //Rememeber that reload time is 10 seconds. You don't want it overpowered.

#define LEVEL4_CLAW_DMG             ADM(110)
#define LEVEL4_CLAW_RANGE           111.0f //128
#define LEVEL4_CLAW_WIDTH           18.0f //20f
#define LEVEL4_CLAW_REPEAT          750 //750
#define LEVEL4_CLAW_K_SCALE         0.8f //i don't mind the knockback, but can get annoying
#define LEVEL4_REGEN_RANGE          200.0f //usually goes unnoticed, left default
#define LEVEL4_REGEN_MOD            1.5f //2 //Can benifit from booster's x3 healing now
#define LEVEL4_CHARGE_SPEED         2.5f //2.5 is easier to move with

#define LEVEL4_CHARGE_TIME          4000 //2000 //This is the time to charge the charge
#define LEVEL4_CHARGE_CHARGE_TIME   4000 //1500 //This is the duration which you charge
//Fuck that. Keep both values the same. Use trampler_charge and charge_take
#define LEVEL4_MIN_CHARGE_TIME      750
#define LEVEL4_CHARGE_CHARGE_RATIO  1.00f//(LEVEL4_CHARGE_CHARGE_TIME/LEVEL4_CHARGE_TIME)//(LEVEL4_CHARGE_TIME/LEVEL4_CHARGE_CHARGE_TIME)
//Fuck that.
#define LEVEL4_CHARGE_REPEAT        100 //1000
#define LEVEL4_CHARGE_DMG           ADM(76) //100 (to help with armoured)
#define LEVEL4_CHARGE_EXTRA         ADM(18)

#define LEVEL4_CHARGE_TAKE          100 //Charge taken per decasecond. Default is 100.
#define LEVEL4_TRAMPLE_CHARGE       200//Charging Charge per decasecond. Default 100. 
#define LEVEL4_TRAMPLE_DMG_B        0.35f //Dmg to buildables 
//rant spit bomb
#define LEVEL4_ABLOB_DMG            ADM(201) //Must not equal to anything else!
#define LEVEL4_ABLOB_DMG_B          ADM(120) //because if damage = previous variable, it is replaced with this one. //TODO: Fix this for buildables [g_combat.c ctrl+F ->hacky fix for ablob]
#define LEVEL4_ABLOB_RADIUS         200 //200 is more than enough to annoy campers
#define LEVEL4_ABLOB_SPEED          500
#define LEVEL4_ABLOB_STUNTIME       1200 //Prevents self from attacking
#define LEVEL4_ABLOB_LIFETIME       10000 //spitbomb lifetime


//Adv Rant experiment
//It worked, but i can't get my client to work. So i undid everything.
/*
#define LEVEL4_UPG_ABLOB_STUNTIME       1500
#define LEVEL4_UPG_ABLOB_DMG            ADM(110)
#define LEVEL4_UPG_ABLOB_RADIUS         200
#define LEVEL4_UPG_ABLOB_SPEED          400
#define LEVEL4_UPG_CHARGE_DMG           ADM(86) //100 (to help with armoured)
#define LEVEL4_UPG_CHARGE_SPEED         2.5f //2.5 is easier to move with
#define LEVEL4_UPG_REGEN_MOD            1.5f //Disabled
*/


/*
 * ALIEN classes
 *
 * _SPEED   - fraction of Q3A run speed the class can move
 * _REGEN   - health per second regained when in creep
 *
 * ALIEN_HLTH_MODIFIER - overall health modifier for coarse tuning
 *
 */

#define ALIEN_HLTH_MODIFIER         1.0f
#define AHM(h)                      ((int)((float)h*ALIEN_HLTH_MODIFIER))

#define ALIEN_VALUE_MODIFIER        1.0f
#define AVM(h)                      ((int)((float)h*ALIEN_VALUE_MODIFIER))

#define ABUILDER_SPEED              0.8f
#define ABUILDER_VALUE              AVM(160) //limit battlegrangers' reward because of newbies
#define ABUILDER_HEALTH             AHM(60)
#define ABUILDER_REGEN              2
#define ABUILDER_COST               0

#define ABUILDER_UPG_SPEED          1.0f
#define ABUILDER_UPG_VALUE          AVM(220) //limit battlegrangers' reward because of newbies
#define ABUILDER_UPG_HEALTH         AHM(90)
#define ABUILDER_UPG_REGEN          2
#define ABUILDER_UPG_COST           0

#define LEVEL0_SPEED                1.4f
#define LEVEL0_VALUE                AVM(180) //default 175, 180 for gpp. I forgot the values for the basilisks and mars. 160 -> 180 because too much complaints about gaining nothing frm dretch kills
#define LEVEL0_HEALTH               AHM(30)
#define LEVEL0_REGEN                1
#define LEVEL0_COST                 0

#define LEVEL1_SPEED                1.2f
#define LEVEL1_VALUE                AVM(260)
#define LEVEL1_HEALTH               AHM(80)
#define LEVEL1_REGEN                2
#define LEVEL1_COST                 1

//head on fighting 1.1 advbasi! Note that human killing one of these will get a lot more credits than normal
#define LEVEL1_UPG_SPEED            1.2f
#define LEVEL1_UPG_VALUE            AVM(475) //275
#define LEVEL1_UPG_HEALTH           AHM(125)
#define LEVEL1_UPG_REGEN            4
#define LEVEL1_UPG_COST             2

#define LEVEL2_SPEED                1.2f
#define LEVEL2_VALUE                AVM(380) //Marauder is chineese cheap. Asians should be able to use this a pwn with it though, while others would waste. So here's the refund. For a massdriver that is.
#define LEVEL2_HEALTH               AHM(100) //Marauder is a glass cannon.
#define LEVEL2_REGEN                3
#define LEVEL2_COST                 1
#define LEVEL1_REGEN_MOD            2.0f

#define LEVEL2_UPG_SPEED            1.3f
#define LEVEL2_UPG_VALUE            AVM(730) //Marauder is a broken character.
#define LEVEL2_UPG_HEALTH           AHM(172) //Previous, 192. Too high, as they steal hp.
#define LEVEL2_UPG_REGEN            5
#define LEVEL2_UPG_COST             3
#define LEVEL1_UPG_REGEN_MOD        3.0f

#define LEVEL3_SPEED                1.1f
#define LEVEL3_VALUE                AVM(575)
#define LEVEL3_HEALTH               AHM(236)
#define LEVEL3_REGEN                6
#define LEVEL3_COST                 2

#define LEVEL3_UPG_SPEED            1.1f
#define LEVEL3_UPG_VALUE            AVM(880)
#define LEVEL3_UPG_HEALTH           AHM(275)
#define LEVEL3_UPG_REGEN            7
#define LEVEL3_UPG_COST             2

#define LEVEL4_SPEED                1.1f //1.2f
#define LEVEL4_VALUE                AVM(1020)//If aliens get 5 evos, humans should get 1000 creds right? Well close enough.
#define LEVEL4_HEALTH               AHM(420)
#define LEVEL4_REGEN                8
#define LEVEL4_COST                 3

#define LEVEL4_UPG_SPEED                1.1f //1.2f
#define LEVEL4_UPG_VALUE                AVM(1200)//If aliens get 5 evos, humans should get 1000 creds right? Well close enough.
#define LEVEL4_UPG_HEALTH               AHM(480)
#define LEVEL4_UPG_REGEN                9
#define LEVEL4_UPG_COST                 5 //9 evos

//Basi-Suit (hidden extra, costing 9 evos, or 11 if tyrant. Somehow this is a wasted class as humans don't 'morph' into a battlesuit, so i can use it as a seperate class unlike gpp =D) Values change for bg_misc.c only.
#define SPY_SPEED                   1.0f //leave as '1.0f' as client overriding cannot happen
#define SPY_HEALTH                  300 //still OP unless you happen to get head-shotted by a luci
#define SPY_VALUE                   720
#define SPY_COST                    1
#define SPY_REGEN                   (9 + (VAMP_ON * -6)) //only regen 3 hp/s with vampire mode on

/*
 * ALIEN buildables
 *
 * _BP            - build points required for this buildable
 * _BT            - build time required for this buildable
 * _REGEN         - the amount of health per second regained
 * _SPLASHDAMGE   - the amount of damage caused by this buildable when melting
 * _SPLASHRADIUS  - the radius around which it does this damage
 *
 * CREEP_BASESIZE - the maximum distance a buildable can be from an egg/overmind
 * ALIEN_BHLTH_MODIFIER - overall health modifier for coarse tuning
 *
 */

#define ALIEN_BHLTH_MODIFIER        1.0f
#define ABHM(h)                     ((int)((float)h*ALIEN_BHLTH_MODIFIER))

#define CREEP_BASESIZE              800 //700
#define CREEP_TIMEOUT               1000
#define CREEP_MODIFIER              0.6f
#define CREEP_ARMOUR_MODIFIER       0.75f
#define CREEP_SCALEDOWN_TIME        3000

#define ASPAWN_BP                   10
#define ASPAWN_BT                   12000
#define ASPAWN_HEALTH               ABHM(275) //250 //has to be killed by one luci shot
#define ASPAWN_REGEN                8
#define ASPAWN_SPLASHDAMAGE         60
#define ASPAWN_SPLASHRADIUS         50
#define ASPAWN_CREEPSIZE            120
#define ASPAWN_VALUE                180 //default 150

#define BARRICADE_BP                8
#define BARRICADE_BT                12000
#define BARRICADE_HEALTH            ABHM(600)//default 200, yes i know thats hell weak. gpp is 300, but i put 600 to deal with luci spammers.
#define BARRICADE_REGEN             32 //regen is high priority as well
#define BARRICADE_SPLASHDAMAGE      150
#define BARRICADE_SPLASHRADIUS      150
#define BARRICADE_CREEPSIZE         240

#define BOOSTER_BP                  12
#define BOOSTER_BT                  15000
#define BOOSTER_HEALTH              ABHM(250) //default 150
#define BOOSTER_REGEN               12
#define BOOSTER_SPLASHDAMAGE        50
#define BOOSTER_SPLASHRADIUS        50
#define BOOSTER_CREEPSIZE           120 //also the size of the area it heals players
#define BOOSTER_INTERVAL            30000 //time in msec between uses (per player) //30000
#define BOOSTER_REGEN_MOD           3.0f //regen multipliyer, default is 2
#define BOOST_TIME                  60000 //poison reload/poison last in alien Default is 30000, gpp should be 20000

#define ACIDTUBE_BP                 6
#define ACIDTUBE_BT                 8000 //15000
#define ACIDTUBE_HEALTH             ABHM(137) //default 125
#define ACIDTUBE_REGEN              9
#define ACIDTUBE_SPLASHDAMAGE       10 //default 4, i'd rather 13-16 for balance to deal with those damn bsuits. Don't get confused this with other splash damages, the others apply to exploding...
#define ACIDTUBE_SPLASHRADIUS       400 //bring higher to near-unite turret range
#define ACIDTUBE_CREEPSIZE          120
#define ACIDTUBE_RANGE              380.0f //200
#define ACIDTUBE_REPEAT             2000
#define ACIDTUBE_K_SCALE            0.2f//1f

#define HIVE_BP                     14
#define HIVE_LIFETIME               10000 //lowered so the hive can fire again faster if human runs
#define HIVE_BT                     20000
#define HIVE_HEALTH                 ABHM(252) //default 125 //252 = rifle's exact damage per clip
#define HIVE_REGEN                  16
#define HIVE_SPLASHDAMAGE           30
#define HIVE_SPLASHRADIUS           80
#define HIVE_CREEPSIZE              120
#define HIVE_RANGE                  900.0f
#define HIVE_REPEAT                 2500
#define HIVE_K_SCALE                -1.0f
#define HIVE_DMG                    97
#define HIVE_SPEED                  380.0f //280 //deal with jettards
#define HIVE_DIR_CHANGE_PERIOD      500
#define HIVE_HIVE_STUN              500//Stun time for insectoid death and rebirth

#define TRAPPER_BP                  8
#define TRAPPER_BT                  6000 //12000
#define TRAPPER_HEALTH              ABHM(60) //default 50
#define TRAPPER_REGEN               6
#define TRAPPER_SPLASHDAMAGE        97
#define TRAPPER_SPLASHRADIUS        90
#define TRAPPER_CREEPSIZE           30
#define TRAPPER_RANGE               600 //default 300 or 200
#define TRAPPER_REPEAT              1000  //Has been added, previously did nothing
#define TRAPPER_K_SCALE             1.0f //explosion. Keep positive for trapper/lockblob jumping.
#define LOCKBLOB_SPEED              650.0f //default 650 //originally 1250 but trappers can't lock humans
#define LOCKBLOB_LOCKTIME           200 //default 6000 //8000 //added to the lock time value for aliens only.
//the REAL lifetime of lock because aliens now get locked as well
//refer to g_missile.c's blob code
#define LOCKBLOB_LIFETIME           6000
#define LOCKBLOB_DOT                0.85f // max angle = acos( LOCKBLOB_DOT )
#define LOCKBLOB_K_SCALE            -1.0f //1.0f
#define LOCKBLOB_DMG                93 //headshots instant kill nakeds! :D //97 -> 93 so lockblob doesnt instant kill marauders

#define OVERMIND_BP                 0
#define OVERMIND_BT                 20000
#define OVERMIND_HEALTH             ABHM(970)
#define OVERMIND_REGEN              24 //16 //32 too high, get in between
#define OVERMIND_SPLASHDAMAGE       18 //18 //36
#define OVERMIND_SPLASHRADIUS       300
#define OVERMIND_CREEPSIZE          120
#define OVERMIND_ATTACK_RANGE       150.0f //100 /200f
#define OVERMIND_ATTACK_REPEAT      800
#define OVERMIND_VALUE              800

#define HOVEL_BP                    0
#define HOVEL_BT                    10000 //Fast-home
#define HOVEL_HEALTH                ABHM(500) //370
#define HOVEL_REGEN                 30 //20
#define HOVEL_SPLASHDAMAGE          20
#define HOVEL_SPLASHRADIUS          200
#define HOVEL_CREEPSIZE             120



/*
 * ALIEN misc
 *
 * ALIENSENSE_RANGE - the distance alien sense is useful for
 *
 */

#define ALIENSENSE_RANGE            1000.0f //look up ^^ usually 1000
#define ALIEN_POISON_TIME           12000 //miliseconds how long poison lasts for, usually 8000
#define ALIEN_POISON_DMG            7 //default 5
#define ALIEN_POISON_DIVIDER        (1.0f/1.32f) //about 1.0/(time`th root of damage)[1.0f/1.32f]

#define ALIEN_SPAWN_REPEAT_TIME     8000 // spawn repeat, default 12000, larger than hspawn

#define ALIEN_REGEN_DAMAGE_TIME     3000 //msec since damage that regen starts again //2000

/*
 * HUMAN weapons
 *
 * _REPEAT  - time between firings
 * _RELOAD  - time needed to reload
 * _PRICE   - amount in credits weapon costs
 * _K_SCALE - Knockback scale
 *
 * HUMAN_WDMG_MODIFIER - overall damage modifier for coarse tuning
 *
 */

#define HUMAN_WDMG_MODIFIER         1.0f
#define HDM(d)                      ((int)((float)d*HUMAN_WDMG_MODIFIER))

#define BLASTER_REPEAT              800
#define BLASTER_K_SCALE             5.0f //knockback now very noticable
#define BLASTER_SPREAD              200 //doesn't work, soon to be fixed
#define BLASTER_SPEED               1400 //1400 //2400
#define BLASTER_DMG                 HDM(120)
#define BLASTER_DMG_MOD             0.1f //Modifier for damage, upper one is used for knockback
#define BLASTER_RADIUS              35
#define BLASTER_SPLASH              HDM(120)
#define BLASTER_CLIPSIZE            6 //disabled
#define BLASTER_MAXCLIPS            9 //disabled
#define BLASTER_MELEE               18 //not too high because it would be overpowered
#define BLASTER_MELLEE_REPEAT       800 //mellee rate
#define BLASTER_MELEE_RANGE         80 //enough for combat

//Rifle is a slow damage dealer, but does a whopping 272 dmg per clip. It is also hard to use without armour support.
#define RIFLE_CLIPSIZE              42
#define RIFLE_MAXCLIPS              9 //6
#define RIFLE_REPEAT                110 //100 //120 (simulates the rate my rifle fires at in gpp)
#define RIFLE_K_SCALE               1.0f
#define RIFLE_RELOAD                1800
#define RIFLE_PRICE                 0
#define RIFLE_SPREAD                170
#define RIFLE_DMG                   HDM(6) //5 //6
//#define RIFLE_SPEED                 9600 //300 m/s

#define PAINSAW_PRICE               100
#define PAINSAW_REPEAT              65 
#define PAINSAW_K_SCALE             1.0f
#define PAINSAW_DAMAGE              HDM(16) //~>250 dmg/s
#define PAINSAW_RANGE               60.0f //40f //enough to touch below feet of a normal human
#define PAINSAW_FUEL                625 //with battpack, 1000
#define PAINSAW_BATTERIES           0 //disabled, rather decay code disallows it from doing anything
#define PAINSAW_RELOAD              3000

//Super Grenade Throw!
#define GRENADE_PRICE               600
#define GRENADE_REPEAT              0
#define GRENADE_K_SCALE             1.0f
#define GRENADE_DAMAGE              HDM(300)//strong enough to kill egg or anything weaker.
#define GRENADE_BUFF                1.50f//If it is caught inside someone, buff it up so the person gibs instantly
#define GRENADE_RANGE               332.0f //192
#define GRENADE_SPEED               780.0f //Throwing speed. Default 400

//reverse pump shotgun
#define SHOTGUN_PRICE               180
#define SHOTGUN_SHELLS              6 
#define SHOTGUN_PELLETS             12
#define SHOTGUN_MAXCLIPS            5
#define SHOTGUN_REPEAT              700
#define SHOTGUN_K_SCALE             2.0f
#define SHOTGUN_RELOAD              ( SHOTGUN_SHELLS * 400 + 800 )
#define SHOTGUN_SPREAD              1320
#define SHOTGUN_DMG                 HDM(6) //spray of defeat - 90dmg/s

#define SHOTGUN_BLAST               48 //damage for secondary blast only.
#define SHOTGUN_BLAST_RANGE         350
#define SHOTGUN_BLAST_REPEAT        1500
//#define SHOTGUN_BLAST_PELLETS       SHOTGUN_SHELLS  //Number of shells per clip, since if i use shells * pellets, the client would fk up
#define SHOTGUN_BLAST_PELLET_DMG    7 //heavy //6 pellets, excluding blast
#define SHOTGUN_BLAST_SPREAD        800 //Blast more accurate

#define LASGUN_PRICE                300 
#define LASGUN_AMMO                 370
#define LASGUN_REPEAT               180 
#define LASGUN_MAXCLIPS             1
#define LASGUN_K_SCALE              2.0f
#define LASGUN_RELOAD               4000
#define LASGUN_SPREAD               100 //works now =P (ripped from mgun)
#define LASGUN_DAMAGE               HDM(10) //9 //60dmg/s, original trem 45dmg/s

//Mass Driver now a Sniper Rifle with a large cooldown
#define MDRIVER_PRICE               380
#define MDRIVER_CLIPSIZE            5
#define MDRIVER_MAXCLIPS            7
#define MDRIVER_DMG                 HDM(62)
#define MDRIVER_REPEAT              1375
#define MDRIVER_K_SCALE             3.0f
#define MDRIVER_RELOAD              4000

//false bullet physics test
#define MDRIVER_SPEED               19200 //Bullet speed 19200 = 600 m/s
#define MDRIVER_RADIUS              35 //explosion radius
#define MDRIVER_SPLASH              30 //Splash dmg - Equal to dretch hp else it can instant kill
#define MDRIVER_LAG                 0.35f //Same effect as Flamer_LAG but not as effective
#define MDRIVER_LIFETIME            8000 //It's a pretty fast bullet. Doesn't need to be that large. Most extreme maps are only a mere 3 seconds diameter. Z-slide is 6 secs across.

//Chaingun actually fires faster
#define CHAINGUN_PRICE              500
#define CHAINGUN_BULLETS            300
#define CHAINGUN_MAXCLIPS           2
#define CHAINGUN_RELOAD             5000
#define CHAINGUN_REPEAT             70 //Single barrel shots
#define CHAINGUN_REPEAT2            90 //tripple barrel shots, total damage per shot stays the same
#define CHAINGUN_K_SCALE            1.0f
#define CHAINGUN_SPREAD             700
#define CHAINGUN_SPREAD2            1000
#define CHAINGUN_DMG                HDM(7)

//Prifle - slow spam, doing max 104 dmg/s

#define PRIFLE_PRICE                580 //cost much? Its like a really strong lasgun in my opinion.
#define PRIFLE_CLIPS                40 //lolards classic: 58 (too overpowered vs goons though)
#define PRIFLE_MAXCLIPS             5
#define PRIFLE_REPEAT               125
#define PRIFLE_K_SCALE              1.0f
#define PRIFLE_RELOAD               2000
#define PRIFLE_DMG                  HDM(13)
#define PRIFLE_SPLASH               HDM(6)
#define PRIFLE_RADIUS               16
#define PRIFLE_SPEED                2000

//Flamer has a realistic shot by halving the repeat rate (2x speed) and halving the dmg
#define FLAMER_PRICE                520
#define FLAMER_GAS                  280
#define FLAMER_RELOAD               3000
#define FLAMER_REPEAT               100
#define FLAMER_K_SCALE              0.5f
#define FLAMER_DMG_MIN              HDM(3)//was going to test this out, scrapped for later
#define FLAMER_DMG                  HDM(11 - FLAMER_DMG_MIN) //20 //2 dmg increase only because we have vampire
#define FLAMER_DMG_MOD              0.6f//Same deal as blaster, this one allows wall climbing.
#define FLAMER_RADIUS_MOD           1.8f //Radius damage mod //Previous variable cancels out this one
#define FLAMER_RADIUS               80 //50
#define FLAMER_LIFETIME             800.0f
#define FLAMER_SPEED                400.0f //300
#define FLAMER_LAG                  0.65f

//Easier to get dretches, and lucijump. Also improved to match tyrant's and other alien's new health.
#define LCANNON_PRICE               700 //should i increase further?
#define LCANNON_AMMO                200
#define LCANNON_REPEAT              1375 //500 //400
#define LCANNON_K_SCALE             3.27f//1f
#define LCANNON_CHARGEREPEAT        500 //800
#define LCANNON_RELOAD              3000 //is reload time too long? //5000 -> 3000
#define LCANNON_DAMAGE              HDM(285) //265 //395 //not too high, too much time range for killing goons making it too easy
#define LCANNON_RADIUS              120 //splash radius. Default 150, wanted 180, but too overpowered
#define LCANNON_SECONDARY_DAMAGE    HDM(85) //default 27
#define LCANNON_SECONDARY_RADIUS    55 //75
#define LCANNON_SPEED               400 //minimum primary speed
#define LCANNON_SECONDARY_SPEED     3600 //Generally higher than 2-3x primary
/*OR you can just read this: It is porportional to how much you power up.
 *What you put here is the MINIMUM speed, and max speed is roughly... uhh lets say around 2.6x this value.
*/

#define LCANNON_CHARGE_TIME         2300 //2000 //dislike long charge times
#define LCANNON_TOTAL_CHARGE        285 //255 //im having trouble with the difference between this and LCANNON_DMG
#define LCANNON_MIN_CHARGE          36 //50 //mincharge dmg value
#define LCANNON_MAXCLIPS	    1 //give some hopes for a human who fired his shots till his battery couldn't handle anymore
//(below 70, the maxcharge lessens.)
#define LCANNON_BATTERY_DECAY       50 //The value by which the luci starts struggling to power a full shot //70->50 because almost useless for non-battpackers
#define LCANNON_TAKE                23.0f //Maximum ammo that can be eaten by one bullet //~8.9 full shots, 10 per second

//Lockblob Launcher
#define LOCKBLOB_AMMO               12
#define LOCKBLOB_MAXCLIPS           9
#define LOCKBLOB_NUKE_REPEAT        2500 //Primary is declared in the alien buildable section for trapper
#define AUTOSHOTTY_REPEAT           300
#define AUTOSHOTTY_PELLET1          5   //Dmg for pellet '1', most accurate
#define AUTOSHOTTY_PELLET2          3   //Dmg for pellet '2', inaccurate accurate
#define AUTOSHOTTY_PELLET3          2   //Dmg for pellet '1', most inaccurate accurate

#define HBUILD_PRICE                0
#define HBUILD_REPEAT               1000 //1000
#define HBUILD_DELAY                17500 //17500
#define HBUILD_HEALRATE             12 //18

#define HBUILD2_PRICE               0
#define HBUILD2_REPEAT              800 //1000
#define HBUILD2_DELAY               10000 //15000

/*
//note: Lockblob launcher is [also] a trapper bomb, see trapper
// vars for changing
*/



/*
 * HUMAN upgrades
 */
#define H_WEAP_SWITCH_DELAY         50//Default 250 //Allow weapon combos

#define LIGHTARMOUR_PRICE           70
#define LIGHTARMOUR_POISON_PROTECTION 2

#define HELMET_PRICE                100 //decreased [from lolards' 130]
#define HELMET_RANGE                1000.0f //1000f //2000.0f
#define HELMET_POISON_PROTECTION    2 

//medkit price
#define MEDKIT_PRICE                0 //Uses credits without medistation to prevent no-medistat bases
//							such as the ones ViruS builds

#define BATTPACK_PRICE              130 //increase as it is very useful //made in a way tha batt+standard armour + luci = 1000 creds, luci + bsuit = 1200 creds)
#define BATTPACK_MODIFIER           1.6f //modifier for extra energy storage available 1.5f

#define JETPACK_PRICE               220 //increased to counter for battpack price
#define JETPACK_FLOAT_SPEED         228.0f //up movement speed //128
#define JETPACK_SINK_SPEED          292.0f //down movement speed //192
#define JETPACK_DISABLE_TIME        1250 //time to disable the jetpack when player damaged //lolards original 600, but knockback from goons only push them up... //Increased to 1250 caus' goon knockback...
#define JETPACK_DISABLE_CHANCE      0.3f //? - doesn't work
#define JETPACK_ACCELERATE          2.00f//default 4.0 //Lolards used to have 2.75, but i consider it overpowered in combat
#define JETPACK_FRICTION            1.8f//old olards used 2.0

#define BSUIT_PRICE                 500
#define BSUIT_POISON_PROTECTION     5

//physical ammo prices, all default 0
#define MGCLIP_PRICE                0

#define CGAMMO_PRICE                0

#define GAS_PRICE                   0

#define MEDKIT_POISON_IMMUNITY_TIME 30000 //default 0
#define MEDKIT_STARTUP_TIME         12000 //4000
#define MEDKIT_STARTUP_SPEED        15 //5


/*
 * HUMAN buildables
 *
 * _BP            - build points required for this buildable
 * _BT            - build time required for this buildable
 * _SPLASHDAMGE   - the amount of damage caused by this buildable when it blows up
 * _SPLASHRADIUS  - the radius around which it does this damage
 *
 * REACTOR_BASESIZE - the maximum distance a buildable can be from an reactor
 * REPEATER_BASESIZE - the maximum distance a buildable can be from a repeaterabout:startpage
 * HUMAN_BHLTH_MODIFIER - overall health modifier for coarse tuning
 *
 * Buildable regeneration speeds are located in bg_misc.c
 */

#define HUMAN_BHLTH_MODIFIER        1.0f
#define HBHM(h)                     ((int)((float)h*HUMAN_BHLTH_MODIFIER))

#define REACTOR_BASESIZE            1200 //1000
#define REPEATER_BASESIZE           500 //500
#define HUMAN_DETONATION_DELAY      3000

#define HSPAWN_BP                   10
#define HSPAWN_BT                   10000
#define HSPAWN_HEALTH               HBHM(310) //210
#define HSPAWN_SPLASHDAMAGE         120 //60
#define HSPAWN_SPLASHRADIUS         100
#define HSPAWN_VALUE                1

#define MEDISTAT_BP                 6
#define MEDISTAT_BT                 8000 //default 10000
#define MEDISTAT_HEALTH             HBHM(190) //190
#define MEDISTAT_SPLASHDAMAGE       50
#define MEDISTAT_SPLASHRADIUS       100


//NOTE: MASSIVE CHANGE TO THE MACHINE GUN TURRET!
//no spinup required!
//IMPORTANT: You should change MGTURRET_FIRE_SPEED and MGTURRET_FIRE_DIRECT_SPEED to 1 if you want the turret to be 'normal'.
//It slows down the turning speed of the turret when it fires.
#define MGTURRET_FIRE_SPEED         0.35 //too hard with dcc up 0.5 -> 0.35
// IF it is directly aiming at it, the following speed multiplier will be used instead.
//It gives a more realistic feel.
#define MGTURRET_FIRE_DIRECT_SPEED  0.1 //too hard with dcc up 0.2 -> 0.1

#define MGTURRET_BP                 8 //8->10 {reverted}
#define MGTURRET_BT                 10000
#define MGTURRET_HEALTH             HBHM(210) //default 190. //increased to cope with tyrant's charge and pounce
#define MGTURRET_SPLASHDAMAGE       60 //50
#define MGTURRET_SPLASHRADIUS       100
#define MGTURRET_ANGULARSPEED       5  //degrees/think 8 ~= 200deg/sec //3 //now 5 because of added MGTURRET_FIRE_SPEED
#define MGTURRET_ACCURACYTOLERANCE  MGTURRET_ANGULARSPEED / 1.5f //1.5 angular difference for turret to fire
#define MGTURRET_VERTICALCAP        45  // -ve minimum pitch //45
#define MGTURRET_DROOPSCALE         0.25     //droop rate when unpowered //0.25
#define MGTURRET_DROOPRATE          50 //x/1000 = droops per second, as well as a repacement for power refreshment time
#define MGTURRET_REPEAT             79 //100
#define MGTURRET_K_SCALE            1.0f
#define MGTURRET_RANGE              580.0f //default 300, same goes for atube
#define MGTURRET_SPREAD             1200 //200
#define MGTURRET_DMG                HDM(6) //4
#define MGTURRET_DCC_ANGULARSPEED       13
#define MGTURRET_DCC_ACCURACYTOLERANCE  MGTURRET_DCC_ANGULARSPEED / 1.5f //1.5f
#define MGTURRET_GRAB_ANGULARSPEED      3
#define MGTURRET_GRAB_ACCURACYTOLERANCE MGTURRET_GRAB_ANGULARSPEED / 1.5f
//sort of a 'proper' version of accuracy tolerance as the pervious one screws up the turret if you raise it.
//This 'range/spread' is a multiplier for the accuracy tolerance before it fires.
#define MGTURRET_ACCURACY_SPREAD        8
//The same thing, but the 'smaller' version of it.
#define MGTURRET_DIRECT_ACCURACY_SPREAD 3
//this is a mutliplier for the ratio of how fast the pitch goes compare to normal. "Normal" is the same value as for yaw. Yaw will stay as MGTURRET_ANGULARSPEED or whatever if it is grabbed.
//For example, normal turning speed is 8 without grab or dcc, therefore:
//*1 = normal = 8
//*0.5 = half = 4
//*2 = Fast rise = 16
//*0 = no rise -> erm...
#define MGTURRET_ACCURACY_PITCH         0.8f
//GPP spinup
//#define MGTURRET_SPINUP_TIME        750 // time between target sighted and fire


#define TESLAGEN_BP                 10
#define TESLAGEN_BT                 15000
#define TESLAGEN_HEALTH             HBHM(280) //210
#define TESLAGEN_SPLASHDAMAGE       60 //default 50
#define TESLAGEN_SPLASHRADIUS       100
#define TESLAGEN_REPEAT             100 //default 250
#define TESLAGEN_K_SCALE            5.0f //4f //higher for lower dmg, be cautious of repeat rates though //6->5 for it sends marauders flying everywhere
#define TESLAGEN_RANGE              280 //default 200 //350 -> 280 so marauders can zap them
#define TESLAGEN_DMG                HDM(5) //default 9

#define DC_BP                       8
#define DC_BT                       10000
#define DC_HEALTH                   HBHM(220) //190
#define DC_SPLASHDAMAGE             100 //50
#define DC_SPLASHRADIUS             120 //100

#define ARMOURY_BP                  10
#define ARMOURY_BT                  17500
#define ARMOURY_HEALTH              HBHM(580) //380 //5 snipes to kill
#define ARMOURY_SPLASHDAMAGE        80 //50
#define ARMOURY_SPLASHRADIUS        200 //100

//Tesla Reactor! =P
#define REACTOR_BP                  0
#define REACTOR_BT                  20000 //default 20000
#define REACTOR_HEALTH              HBHM(1200) //930 -> 970 -> 1200 //Too weak
#define REACTOR_SPLASHDAMAGE        300 //200/100
#define REACTOR_SPLASHRADIUS        ( 1.5 * REPEATER_BASESIZE ) //300 -> 780
#define REACTOR_ATTACK_RANGE        180.0f //120
#define REACTOR_ATTACK_REPEAT       125 //1000
#define REACTOR_ATTACK_DAMAGE       6 //30 //8 is too strong and can't be hopped
#define REACTOR_VALUE               4

//nuclear repeater
#define REPEATER_BP                 3
#define REPEATER_BT                 10000
#define REPEATER_HEALTH             HBHM(300) //250
#define REPEATER_SPLASHDAMAGE       200 //50 //crazy nuke
#define REPEATER_SPLASHRADIUS       REPEATER_BASESIZE // 100
#define REPEATER_INACTIVE_TIME      180000 //3 minutes or else... Boom!

/*
 * HUMAN misc
 * Usually this: (in order) - 1.2f  1.0f  0.8f  0.9f | 25  15  8  4
 */

#define HUMAN_SPRINT_MODIFIER       1.3f //sprint multiplyer //1.2
#define HUMAN_JOG_MODIFIER          1.0f // normal human speed
#define HUMAN_BACK_MODIFIER         0.8f //to stop back pedaling
#define HUMAN_SIDE_MODIFIER         0.9f // dodging/straifing sideways

#define STAMINA_STOP_RESTORE        7 //restore stamina by stopping //35
#define STAMINA_WALK_RESTORE        4 //or walking //18
#define STAMINA_SPRINT_TAKE         2 //taking stamina away by sprinting //8 //9
#define STAMINA_LARMOUR_TAKE        3 //It replaces sprint_take when having larmour. According to g_active.c //12
#define STAMINA_BSUIT_STOP_RESTORE  8 //40
#define STAMINA_BSUIT_WALK_RESTORE  5 //20
#define STAMINA_JUMP                60 //vanilla 1.1: 500 Lolards 300
#define STAMINA_MIN_TO_JUMP         -800//0 Lolards -500

#define HUMAN_SPAWN_REPEAT_TIME     8000 //spawn timing,default 8000
#define HUMAN_REGEN                 1 //int (per ALIENREGEN_NOCREEP_MOD) per second

/*
 * Misc
 */

#define MIN_FALL_DISTANCE           30.0f //the fall distance at which fall damage kicks in //20f
#define MAX_FALL_DISTANCE           720.0f //the fall distance at which maximum damage is dealt //240f //change higher to 360 //changed higher to 720 because more damage is delt at maximum damage
#define AVG_FALL_DISTANCE           ((MIN_FALL_DISTANCE+MAX_FALL_DISTANCE)/2.0f)

#define HUMAN_MAXED                 1200   //a human with a strong selection of weapons/upgrades // means max 'evos' [after conversion] that an alien can get. Default 900
#define HUMAN_MAX_CREDITS           3000 //max creds, usually 2000
#define ALIEN_MAX_KILLS             15 //max evos //13->15 because human can buy two sets of lucisuits, aliens need to be able to use two ranties
#define ALIEN_MAX_SINGLE_KILLS      5 //Max evos earned from HUMAN_MAXED i guess... i never looked into this //3->4->5

#define FREEKILL_PERIOD             60000 //msec //60 secs because things are more costy
#define FREEKILL_ALIEN              1 // one evo per 120000 miliseconds or whatever FREEKILL_PERIOD is.
#define FREEKILL_HUMAN              200 // LEVEL0_VALUE is default. 220 is enough for lasgun and larmour, but when it stacks, it gives to much in total, might increase back to 220 in future

//thresholds usually 20, then 40, bp is 100 both, but usually prefered 150 for aliens.
#define DEFAULT_ALIEN_BUILDPOINTS   "200"
#define DEFAULT_ALIEN_STAGE2_THRESH "35"
#define DEFAULT_ALIEN_STAGE3_THRESH "90"
#define DEFAULT_ALIEN_MAX_STAGE     "2"
#define DEFAULT_HUMAN_BUILDPOINTS   "160" //raised due to turret rise //decreased for lowering turret back to 8 bp
#define DEFAULT_HUMAN_STAGE2_THRESH "35"
#define DEFAULT_HUMAN_STAGE3_THRESH "90"
#define DEFAULT_HUMAN_MAX_STAGE     "2"

#define DAMAGE_FRACTION_FOR_KILL    0.5f //how much damage players (versus structures) need to
                                         //do to increment the stage kill counters. Usually 0.5. I had 0.9 but that made humans come up slowly since they like camping. Encourage them to get out giving them s3.

//Vampire mode settings
//see g_combat.c for the equation. Search for #define vamp

#define VAMP_ON                     0 //Used to balance some things above. Does not effect vampire code.
//TODO: Change into CVAR
//Test
/*
int vampireon 0;
if( g_vampiremode.integer == 1 )
{
vampireon = 1;
}
#define VAMP_ON vampireon
*/	
//Endtest

#define VAMP_EXTRA                  50 //50
#define VAMP_TAKE_MULTIPLIER        (1.00f*(VAMP_ON)/600) //see g_combat.c why it needs to be a small number

#define VAMP_DIVIDE                 10   //cancelled out by a comment, but keep for future prefs.
#define VAMP_TAKE                   6.25 //6.25//Confusing, recommended to leave as is. Basically at MAX-vamp'd health, you lose 4 times as much as you would with 25% vamp'd health
                                       //Human max extra health is 50, so it takes 8 hp/s at most...
#define MAX_MAX_HEALTH              1.0f //Max health for players * this = Max vamped health, in this case its 1+(if vamp is on/off [1/0]*0.5) = 1.5x normal max health
                                         //ALWAYS ABOVE ZERO, and use a float value if not 1.0
//medkit extras
#define MEDKIT_OVERHEAL             1.0f //yes = >1.0f no = 1.0f little = 1.2f //Note: Has to be under MAX_MAX_HEALTH, else it only heals the extra as you're damaged
#define MEDKIT_EXTRA                20 //Extra raw health added to medkit //Lolards original = 80

// g_suddenDeathMode settings
#define SDMODE_BP                   ( REPEATER_BP + ARMOURY_BP + DC_BP + MEDISTAT_BP ) // This is why gpp sudden death sucks, you can't build an armoury. Here, you can build a maximum of one armoury,a reactor and medi, dcc and repeater. 
#define SDMODE_NO_BUILD             0 // 1 for totally out
#define SDMODE_SELECTIVE            0 //2 //i should put '1' but it doesnt work, 0 somewhat only allows rebuilding of structures i allowed which should be as status '1'.
