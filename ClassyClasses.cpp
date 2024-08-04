/*            */
//  fatpound* //
/*            */

module; // I add that to the top of module files
// Not going to comment it out, even if I wont use any includes

// I use the word library ==> header here.
// if I'm going to use any of the Windows libraries, I include my FatWin32_.hpp file first
#include <Windows.h> // Windows.h at the top, or FatWin32_.hpp

// defines can appear here if needed, obviously
// my headers with the following "furthest first" order, if there's no problems
// every "category" is divided by a blank line
#include "../../Header.hpp"

#include "../Header.hpp"

#include "Header.hpp"
// I dont like using .h or .hh extensions for cpp headers

#include <DirectXMath.h> // DXmath first

#include <d2d1.h>        // DirectX libraries
#include <d2d1_1.h>
#include <d2d1_2.h>
#include <d2d1_3.h>
#include <d3d11.h>

// maybe Microsoft GSL or SAL libraries here

#include <wrl.h>         // WinAPI libraries

#include <crtdbg.h>      // then Win32 CRT libraries

#include <direct.h>      // windows C libraries
#include <conio.h>

// unix C libraries if needed e.g. <unistd.h>

#include <stdio.h>       // c libraries
#include <stdlib.h>

#include <cmath>         // c libraries for c++
#include <cstdlib>       // c libraries for c++

#include <string>        // c++ libraries last
// latest c++ libs may and should appear at the bottom, like c++23's stacktrace
// but thats not important actually

// defines -> between includes and pragmas
#define FATPOUND

#define MACRO(x) ((x) ? true : 0)

#define FAT_NAMESPACE_WIN32 ::fatpound::win32

// library linking pragmas and warning controlling...
// they can appear before the includes
// for example, we may want to disable a specific warning for a header file
#pragma comment(lib, "d3d11")

#pragma warning(disable : 4820)

// (export) module FatPound; // this is obviously here

// I prefer using namespace aliases in the cpp file, if we're not in an ixx file
namespace fat = fatpound;
namespace snd = fatpound::sandbox

namespace d2 = D2D1;
namespace dx = DirectX;
namespace wrl = Microsoft::WRL;

namespace fs = std::filesystem;
namespace rn = std::ranges;
namespace vi = std::views;

// I dont like "using namespace" in the global scope in a file;
// If I were to use it, I would only use it in small scopes, function scopes or cpp file scope
// like here, before 'everything' such as namespace or class declarations or functions

// BUT, I may use using namespace std::literals; here... idk

// THE CLASS
// friends first
// using aliases next

// public first,
// protected mid,
// private last

// ^^^ even if there's nothing in the class, I still write
// all of these access specifiers (only once in this context)

// I dont start class names with a 'C' but I may apply this style in the future
class CClass
{
public:


protected:


private:
}

// for every kind of an access modifier, the following ordering rule is applied:
// (if exists obviously)
// enum (traditional)
// enum struct
// enum class
// struct
// class
// union

// abstract structures appear first, for example:
//
// public:
// struct SAbstract {}; // this is abstract
// struct SNormal {};   // this is normal

// and then.............
// operators
// static functions
// virtual methods
// methods

// this rule is applied to method ordering
// method()
// method() &
// method() &&

namespace test
{
    class FCC;
}

template <typename T>
requires Concept<T> // I may put that after the template, not on a newline but idk
class CTest final : virtual public Base
{
    friend class FC;
    friend ::test::FCC; // I dont use this declaration style (no class keyword)
    //     ^^ I probably will use the scope resolution operator if the class is in another namespace
    // in this case, I shouldn't add it since CTest class is just in the global namespace

    using Base::Base;

    using Base::StaticMethod1;      // I don't recommend this
    using Base::StaticMethod2_;

    using Base::member1;            // also, I don't like this, I may use Base members by writing this->
    using Base::member2_;
        // <- only one space here
public:
    enum E
    {

    };
        // <- two empty lines between every access specifier
        // except for nested structures
public:
    enum struct ES // I can add final on scoped enums only on MSVC but IntelliSense gets angry
    {

    };


public:
    enum class EC
    {

    };


public:
    struct S
    {

    };


public:
    // notice that I always indicate (and write) the access specifiers on classes
    // I dont usually do the same for other structure types
    class C
    {
    public:
    
    protected:

    private:
    };


public:
    union U
    {

    };


public:
    // I prefer giving the variables
    // a name even in the hpp file
    CTest(int x, int y);                               // other ctors

    CTest() = default;                                 // ctor
    CTest(const CTest& src) = default;                 // copy ctor
    CTest& operator = (const CTest& src) = default;    // copy assignment
    // I'm thinking about adding a space here to make the code more readable
    CTest(CTest&& src) = default;                      // move ctor
    CTest& operator = (CTest&& src) = default;         // move assignment
    ~CTest() noexcept = default;                       // dtor (always noexcept)
    // I prefer making ctors default or deleted
    // in the hpp file
    // and, I use the name "src" for move and copy ctors and assignments' parameters


public:
    auto operator () () -> std::string;
    // I like putting a space between parantheses and operator keyword


public:
    // I need to re-think this order but it seems OK

    // concept + requires templated methods
    // concept templated methods
    // requires templated methods
    // templated methods
    // TO BE CONTINUED

    static void s1() noexcept(IN_RELEASE);

    static void s2() noexcept(true);

    static void s3() noexcept;

    static void s4() noexcept(false);

    static void s5();


public:
    // methods are ordered by return types FIRST
    // then override specifiers in the following order:

    virtual void v1() final = 0;       // pure virtual final (if needed such a thing)

    virtual void v2() = 0;             // pure virtual

    virtual void v3() override final;  // virtual override final

    virtual void v4() final;           // virtual final

    virtual void v5() override;        // virtual override

    virtual void v6();                 // just virtual


public:
    // primitive types with more bytes first in every category
    // floating points first, then integrals

    // I will explain auto's here later on

    long double f1();
    double f2();

    float f3();

    long long int f4();
    long int f5();
    int f6(); 
    short int f7();             
    unsigned int f8();      // I don't like writing unsigned (or signed) without the type because it may be char too

    signed char f9();       // If signed is written explicitly, it comes before regular one
    char f10();
    unsigned char f11();

    bool f12();

    void f13();
    void f14() &;
    void f15() &&;


protected:
    // protected and private names end with an underscore
    void f1_();


private:
    // static variables' names start with an "s_"
    // member variables' names start with an "m_"
    // pointers, references, and "handle"s are written in camelCase, not snake_case like other member variables.
    ::Microsoft::WRL::ComPtr<ID3D11Device> m_pDevice_ = nullptr;
    ::HWND m_hWnd_ = nullptr;

    std::vector<int> m_vec_;

    std::string m_str_;

    T m_var;

    inline static bool s_flag = true;

    static int s_integer;

    static constinit int s_int1;          

    static constexpr int s_int2;
    
    static constexpr auto s_text_ = L"FatPound";
};

module : private;
// I don't add an empty newline at the end if I use MSVC
// to be continued
