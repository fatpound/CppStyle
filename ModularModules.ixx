/*            */
//  fatpound* //
/*            */

module; // I add that to the top of module files
// even if I wont use any preprocessor directives

// if I'm going to use any of the Windows headers, I include my FatWin32_.hpp file first
#include <Windows.h> // Windows.h at the top, or FatWin32_.hpp

// defines can appear here if needed, obviously
// my headers with the following "furthest first" order, if there's no problems
// every "category" is divided by a blank line
#include "../../Header.hpp"

#include "../Header.hpp"

#include "Header.hpp"

#include <d2d1.h>        // DirectX headers first
#include <d2d1_1.h>
#include <d2d1_2.h>
#include <d2d1_3.h>
#include <d3d11.h>

#include <DirectXMath.h> // DXmath first

// maybe Microsoft GSL or SAL libraries here

#include <wrl.h>         // WinAPI libraries

#include <crtdbg.h>      // then Win32 CRT libraries

#include <direct.h>      // windows C libraries
#include <conio.h>

// unix C libraries if needed e.g. <unistd.h>

#include <stdio.h>       // standard c libraries
#include <stdlib.h>

#include <cmath>         // standard c libraries for c++
#include <cstdlib>       // standard c libraries for c++

#include <string>        // standard c++ libraries
// latest std c++ libs should appear at the bottom, like c++23's stacktrace

// defines -> between includes and pragmas
#define FATPOUND

#define MACRO(x) ((x) ? true : 0)

#define FATSPACE_WIN32 ::fatpound::win32

// library linking pragmas and warning controlling...
// they can appear before the includes
// for example, we may want to disable a specific warning for a header file
#pragma comment(lib, "d3d11")

#pragma warning(disable : 4820)

export module FatPound;

// I prefer adding a space between import "categories" but its not needed, see #2
// I prefer alphabetically ordered imports (extensions first except WinAPI wrappers)

export import <Windows.h>;
export import <A.hxx>;

export import :IntfPart;
export import :IntfPart.Two;
export import :IntfPart.Two.Three;

import <FatWin32.hxx>;
import <d3d11.h>;
import <B.hxx>;

import :ImplPart;
import :ImplPart.Two;
import :ImplPart.Two.Three;

import A;
import B;
import C;

import FatPound.Color;
import FatPound.Utility;
import FatPound.Win32.Common;
import FatPound.Win32.D3D11.Graphics;

import boost.regex;
import glm;
import seastar;

import std;
import std.compat;

namespace snd = fatpound::sandbox;

namespace d2  = D2D1;
namespace dx  = DirectX;
namespace wrl = Microsoft::WRL;

namespace fs = std::filesystem;
namespace rn = std::ranges;
namespace vi = std::views;

module : private;
