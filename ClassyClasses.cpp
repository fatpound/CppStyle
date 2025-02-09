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

#include <stdio.h>       // standard c libraries
#include <stdlib.h>

#include <cmath>         // standard c libraries for c++
#include <cstdlib>       // standard c libraries for c++

#include <string>        // standard c++ libraries
// latest std c++ libs should appear at the bottom, like c++23's stacktrace

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

// I prefer using namespace aliases in global namespace scope ONLY in the regular cpp file
// if we're in a module unit (file), it does not matter that much. But even if I use modules,
// I use namespace aliases in module implementation units (files).
namespace fat = fatpound;
namespace snd = fatpound::sandbox

namespace d2 = D2D1;
namespace dx = DirectX;
namespace wrl = Microsoft::WRL;

namespace fs = std::filesystem;
namespace rn = std::ranges;
namespace vi = std::views;

// I dont like "using namespace" in the global scope in a file, BUT
// If I were to use it, I would only use it in small scopes, small C++ test codes,
// function scopes
// If I just test some C++ standard compliance test of a compiler, I would use it anywhere like here, before 'everything'

// BUT, I may use using namespace std::literals; here... idk
// They should obey the rule as using namespace ...'s rules;

// THE CLASS
// friends first
// using aliases next

// public first,
// protected mid,
// private last

// ^^^ even if there's nothing in the class, I still write
// all of these access specifiers (only once in this context)

// I dont start class names with a 'C' but I might apply this style in the future
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

// abstract (interface) structures appear first, for example:
//
// public:
// struct SITest {};
// struct SAbstract {};
// struct SNormal {};

// and then.............
// operators
// static member functions     // function templates appear first in every category
// virtual member functions
// member functions

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
class CTest final : virtual public Base // first virtual, then access specifier keyword
{
    friend class FC;
    friend ::test::FCC; // I dont use this declaration style (no class keyword)
    //     ^^ I probably will use the scope resolution operator if the class is in another namespace
    // in this case, I shouldn't add it since CTest class is just in the global namespace

    // static constexpr member variables are always on top, unless they are non-private
    // their names start with "scx_"
    // static constinit member variables are almost the same, but their names start with "sci_"
    // AND see member variable naming rules, at the bottom of this class
    // AND constinit member variables appear first
    static constinit int sci_special_val_;

    static constexpr int scx_int2 = 100;
    static constexpr auto scx_text_ = L"FatPound";

    typedef auto(*pf0)() -> void;
    typedef void(*pf1)();

    typedef int arr1d_t[7];
    typedef int arr2d_t[7][7];
    typedef int arr3d_t[7][7][7];

    typedef std::uint8_t BYTE;

    using Vector_t = std::vector<T>; // type aliases, following friend class declarations

    using Base::Base;

    using Base::StaticMemberFunc1;   // I don't recommend this
    using Base::StaticMemberFunc2_;

    using Base::member1;             // also, I don't like this, I may use Base members by writing Base:: or maybe this->
    using Base::member2_;
    // <- only one space here
public:
    using type       = CTest; // non private type aliases
    using value_type = T;


public:
    enum E
    {

    };
    // <- two empty lines between every access specifier
    // except for nested structures, they should have only 1 space between those access specifiers.
public:
    enum struct ES // I can add final on scoped enums only on MSVC but IntelliSense complains
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
    struct Strak  {}; // if there is a need for empty base classes, like, for template mp, I can one-line a structure
    struct Strakt {};


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
    // I like adding a space between operator keyword and the operator token
    auto operator ++ ()    -> CTest&;
    auto operator ++ (int) -> CTest;
    auto operator -- ()    -> CTest&;
    auto operator -- (int) -> CTest;

    auto operator +  () -> CTest;
    auto operator -  () -> CTest;
    
    auto operator +  (const CTest& rhs) -> CTest;
    auto operator -  (const CTest& rhs) -> CTest;
    auto operator *  (const CTest& rhs) -> CTest;
    auto operator /  (const CTest& rhs) -> CTest;
    auto operator %  (const CTest& rhs) -> CTest;
    auto operator += (const CTest& rhs) -> CTest&;
    auto operator -= (const CTest& rhs) -> CTest&;
    auto operator *= (const CTest& rhs) -> CTest&;
    auto operator /= (const CTest& rhs) -> CTest&;
    auto operator %= (const CTest& rhs) -> CTest&;

    auto operator ^  (const CTest& rhs) -> auto;
    auto operator |  (const CTest& rhs) -> auto;
    auto operator &  (const CTest& rhs) -> auto;
    auto operator ^= (const CTest& rhs) -> auto;
    auto operator |= (const CTest& rhs) -> auto;
    auto operator &= (const CTest& rhs) -> auto;

    // auto operator xor    (const CTest& rhs) -> auto;
    // auto operator bitor  (const CTest& rhs) -> auto;
    // auto operator bitand (const CTest& rhs) -> auto;
    // auto operator xor_eq (const CTest& rhs) -> auto;
    // auto operator or_eq  (const CTest& rhs) -> auto;
    // auto operator and_eq (const CTest& rhs) -> auto;

    auto operator <=> (const CTest& rhs) -> auto;

    auto operator ==  (const CTest& rhs) -> bool;
    auto operator !=  (const CTest& rhs) -> bool; // not_eq
    auto operator >   (const CTest& rhs) -> bool;
    auto operator <   (const CTest& rhs) -> bool;
    auto operator >=  (const CTest& rhs) -> bool;
    auto operator <=  (const CTest& rhs) -> bool;

    auto operator !  () -> bool;   // not
    auto operator &  () -> CTest*;
    auto operator -> () -> CTest*;
    auto operator ~  () -> CTest;  // compl
    auto operator ,  (const T& val) -> CTest*;
    auto operator [] (const std::size_t& index) -> T;
    auto operator () () -> std::string;
    auto operator co_await () -> auto;

    explicit(true)  operator int ();
    explicit        operator double ();
    explicit(false) operator char ();

    template <typename T>
    operator T ();

    operator void ();


public:
    // concept + requires + requires templated methods
    // concept + requires templated methods
    // concept templated methods
    // requires templated methods
    // templated methods

    // abbreviated template syntax:
    // constrained auto first
    // auto last

    // template <std::integral N>
    // requires requires { requires true; }
    // static void s() requires requires { requires true; };

    template <std::integral N>
    requires true
    static void s() requires true;

    template <std::integral N>
    requires true
    static void s();
    
    template <std::integral N>
    static void s() requires true;

    template <std::integral N>
    static void s();

    template <typename T>
    static void s() requires true;

    template <typename T>
    static void s();

    static void s(std::integral auto N);
    static void s(auto N);

    // non templated member functions are next
    // noexcept specifier order is like this
    static void s1() noexcept(noexcept(true));

    static void s1() noexcept(IN_RELEASE);

    static void s2() noexcept(true);

    static void s3() noexcept;

    static void s4() noexcept(false);

    static void s5();


public:
    // virtual methods must be specified with virtual keyword
    // then override specifiers in the following order:

    virtual void v1() final = 0;       // pure virtual final ? (if needed such a thing)

    virtual void v2() = 0;             // pure virtual

    virtual void v3() override final;  // virtual override final (I do not like "final override")

    virtual void v4() final;           // virtual final

    virtual void v5() override;        // virtual override

    virtual void v6();                 // just virtual


public:
    // all methods are ordered by return types FIRST
    // primitive types with more storage space appear first in every category
    // real numbers first, then integrals

    auto f0() -> std::integral auto;
    
    auto f0() -> auto;

    auto f0() -> CTest;
    auto f0() -> CTest*;
    auto f0() -> CTest&;

    long double f1();

    double f2();

    float f3();

    signed long long int f4();
    signed long long f4();
    long long int f4();
    long long f4();

    unsigned long long int f4();
    unsigned long long f4();

    signed long int f4();
    signed long f4();
    long int f4();
    long f4(); 

    signed int f();
    signed f();
    int f6();

    unsigned int f8();
    unsigned f();

    signed short int f7();
    signed short f7();
    short int f7();
    short f7();

    unsigned short int f7();
    unsigned short f7();

    char f10();
    signed char f9();
    unsigned char f11();

    bool f12();

    // If cvr qualifiers are written in method declarations / definitions, then it must be in this order:
    void f13() &;
    void f13() &&;
    void f14();
    void f15() &;
    void f15() const &;
    void f15() volatile &;
    void f15() const volatile &;
    void f15() &&;
    void f15() const &&;
    void f15() volatile &&;
    void f15() const volatile &&;


protected:
    // protected and private names end with an underscore
    void f1_();


private:
    // member variable naming rules
    // static   ones start with an "s*_"
    // member   ones start with an "m*_"
    // const    ones start with an "*c_"
    // volatile ones start with an "*v_"

    // inlines first
    inline static bool s_flag_ = true;

    static int s_ival_;
    static const int sc_ival_;


private:
    // pointers, references, and "handle"s are written in camelCase,
    // not snake_case like other member variables.
    Microsoft::WRL::ComPtr<ID3D11Device> m_pDevice_ = nullptr; // I might change this naming rule for smart pointer objects, in the future.
    HWND m_hWnd_ = nullptr;

    std::vector<int> m_vec_;

    std::string m_str_;

    T m_var_;
};

module : private;
// I don't add an empty newline at the end if I use MSVC
