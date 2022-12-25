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

#include "blackrock_foundry.h"

std::vector<Position> const g_GraspingEarthSpawnPos =
{
    { 329.81f, 3673.47f, 105.0969f, 0.0f },
    { 320.84f, 3669.83f, 105.0969f, 0.0f },
    { 309.80f, 3667.69f, 105.0969f, 0.0f },
    { 334.03f, 3663.56f, 105.0969f, 0.0f },
    { 325.15f, 3661.87f, 105.0969f, 0.0f },
    { 315.54f, 3660.95f, 105.0969f, 0.0f },
    { 303.60f, 3659.29f, 105.0969f, 0.0f },
    { 324.41f, 3652.30f, 105.0969f, 0.0f },
    { 315.57f, 3650.33f, 105.0969f, 0.0f },
    { 332.94f, 3649.88f, 105.0969f, 0.0f },
    { 306.76f, 3649.72f, 105.0969f, 0.0f },
    { 324.18f, 3642.71f, 105.0969f, 0.0f },
    { 315.93f, 3641.32f, 105.0969f, 0.0f },
    { 308.55f, 3640.92f, 105.0969f, 0.0f },
    { 331.65f, 3636.36f, 105.0969f, 0.0f },
    { 304.03f, 3633.00f, 105.0969f, 0.0f },
    { 317.41f, 3632.95f, 105.0969f, 0.0f },
    { 310.38f, 3631.94f, 105.0969f, 0.0f },
    { 325.00f, 3630.81f, 105.0969f, 0.0f },
    { 317.63f, 3624.18f, 105.0969f, 0.0f },
    { 306.16f, 3623.51f, 105.0969f, 0.0f },
    { 330.92f, 3623.30f, 105.0969f, 0.0f },
    { 312.64f, 3617.37f, 105.0969f, 0.0f },
    { 323.41f, 3615.52f, 105.0969f, 0.0f },
    { 306.78f, 3612.18f, 105.0969f, 0.0f },
    { 333.36f, 3611.77f, 105.0969f, 0.0f },
    { 318.56f, 3605.63f, 105.0969f, 0.0f },
    { 328.65f, 3604.92f, 105.0969f, 0.0f },
    { 308.19f, 3603.65f, 105.0969f, 0.0f },
    { 336.12f, 3597.34f, 105.0969f, 0.0f },
    { 325.87f, 3596.64f, 105.0969f, 0.0f },
    { 315.58f, 3594.69f, 105.0969f, 0.0f },
    { 306.78f, 3594.69f, 105.0969f, 0.0f },
    { 323.10f, 3587.57f, 105.0969f, 0.0f },
    { 333.16f, 3587.45f, 105.0969f, 0.0f }
};

/// Use for killing players who falls on Kromog's feet
float g_AllowedDist = 22.0f;
float g_FloorZ      = 65.0f;
