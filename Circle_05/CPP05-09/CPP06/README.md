CPP06

[ Goal ]
To learn about the explicit type conversion safely

[ Background ]
1) Scientific notation
    = Normalization

    (1) Binary
        128 = 1.00 x 2^7
                 f x b^e

        65 = 1.000001 x 2^6
                    f x b^e

        = 'b' always 2

    (2) Decimal
        123 = 1.23 x 10^2
                f  x  b^e

        = 'b' always 10

    = We don't need to care about 'b', only need 'f, e'.
    = Effiecient.

2) Up-casting & Down-casting
    (1) Up-casting
	= 하위 클래스(derived class) 객체를 상위 클래스(base class) 타입으로 변환
        1. Child -> Parent
        2. Safe
        3. Auto-converting
           = Implicit Conversion
           = C++ 컴파일러가 자동으로 변환.

        ex)
        class Base {};
        class Derived : public Base {};
        Base* base = new Derived();  // 자동 변환
    
    (2) Down-casting
	= 상위 클래스(base class) 객체를 하위 클래스(derived class) 타입으로 변환
        1. Parent -> Child
        2. Dangerous
        3. static_cast || dynamic_cast
              = 자동 변환되지 않으며, 반드시 캐스팅을 명시해야 함.

        ex)
        Base* base = new Derived();
        Derived* derived = dynamic_cast<Derived*>(base);  // down-casting
        if (derived) {
            // 변환 성공
        }

3) float & double 
float
    Single Precision, 32-bit floating point format. 7 decimal digits for precision.

double
    Double Precision, 64-bit floating point format. 15 decimal digits for precision.

[ Overview ]      
Explicit Conversion (명시적 변환)

ex00: static_cast
ex01: reinterpret_cast
ex02: dynamic_cast

             Check safty   Safty   Converting for          In inheritance relationship
static       Compile time    2     Built-in data type          O
reinterpret      X           3     Forced type conversion      X
dynamic      Run time        1     Safe inheritance rela.      O

[ Detail ]
1) static_cast<type>(expression)
    1. Converting
    - Built-in(already defined primitive) data type conversion
        ex) int, char, float, double, string
    - Compatibility // 타입 호환성되는 요소들끼리
        ex) int <-> float, float <-> double
    - Up-casting
      = Child to parent, between classes in an inheritance relationship.
        ex) Dog -> Animal

    2. safety check
        To check the type at the compile time.

    3. Features
        Not make object, just use 'class' itself.
        = Low memory usage, save time, simple readable code.
    
    = 명확한 변환이 필요할 때 사용.

2) reinterpret_cast<type>(expression)
    1. Converting
    - 포인터 간의 형 변환
    - 정수 <-> 포인터간 형 변환도 가능.

    2. Bit converting
    - 데이터를 완전히 다른 새로운 타입으로 변환 가능
    - 메모리 비트 패턴을 직접 변환
      메모리에 저장된 값을 건드리지않고 다른 방식(타입)으로 읽는다.
    - 비트단위로 변환시키기에 서로 관계없는 타입 간 무조건 형 변환이 가능하다.

    3. Dangerous
    - 두 타입 간의 메모리 구조가 일치하지 않더라도 강제로 변환.
    - 컴파일러에서 검사를 하지 않기에 오류 나면 위험하다.
    - 일반적으로 허용되지 않는 위험한 형 변환을 할 때 사용.
    - UB(Undefined Behavior, 정의되지 않은 동작) 발생 가능

    4. Cut 'data'
    - ex) int a = 123;
          char* ptr = reinterpret_cast<char *>(&a);

        int type: 4bytes.
        char type: 1bye.

    - If convert success, read only 1byte, cause it's char.
      = 데이터가 잘려서 읽힌다.

    = 웬만하면 사용하지 않는 게 좋음.

3) dynamic_cast<Type>(expression)
    1. Converting
    - Down-casting
      = Parent to child, between classes in an inheritance relationship.
        ex) Animal -> Dog
     
    - IMPOSSIBLE: Between already defined basic data types each other.
      = 기본 자료형 간의 형변환 불가

    2. Safety check
    - Runtime
        런타임시에 실제로 캐스팅 가능한지 검사를 한다.
        RTTI(Run-Time Type Information)를 사용해서 검사한다.
        C++에서는 이 정보를 vtable에 저장한다.
        가상 함수가 없는 클래스에는 vtable이 없고, RTTI 정보도 없다.
        RTTI 정보가 없어서 dynamic_cast를 사용할 수 없음.
    
      = dynamic_cast는 가상 함수가 있는 클래스에서만 사용 가능하다.
      = It's safer than <static_cast>.

    3. Return
       fail -> nullptr // safe

4) const_cast<type>(expression)
    1. const를 제거하는 데 사용하는 캐스트 연산자
    2. const 속성을 영구적으로 제거하는 것은 아니고 일시적으로 값변환을 가능하게 한다.

--------------------------------------------------------------------------------

[ ex00 ] static_cast
(1) In-short
    기본 자료형간 타입 변환 with [static_cast]

    1. Define a class called Converter.
    2. Write functions that receive standard input values ​​as strings.
    3. Convert them to basic data types, and then output them to the terminal.

(2) Class
    'Converter'

(3) Logic
    1. Get the string type av[1]
    2. Convert it to the basic datatype (char, int, float, double)
    3. Print it to the terminal.

    = Since only type conversion between basic data types is required,
      the <static_cast> operation can be onlt used in this exercise.

(4) Error handling during the conversion
    - Non displayable   |   Not printable (Not ASCII)
    - impossible        |   Non convertalbe (ex: string to int)
    - NaN               |   Not a number (ex: 0.0 / 0.0, std::sqrt(-1.0), inf - inf, nan + 1.0)
    - nanf              |   nan + 'f'    // float version of the 'nan'
    - inf               |   Infinity (Double type) 무한대
    - inff              |   Infinity (Float type)  무한대 (1.0 / 0.0)
    - *                 |   ETC

(5) Forbidden
    std::stoi, std::stof, std::stod // C++11
    = (USE) std::atoi, std::atof, std::strtod

--------------------------------------------------------------------------------

[ ex01 ] reinterpret_cast
(1) In-short
    포인터와 관련된 타입 변환을 with [reinterpret_cast]

(2) Background knowledge
    
    1) Serialization & deserialization
        데이터 직렬화
        메모리를 디스크에 저장하거나,
        네트워크 통신에 사용하기 위한 형식으로 변환하는 것.

    2) Memory structure
        1. Value type
            ex) int, float, char, ..
            = Store actual value in 'Stack'
            = Directly contact available.

        2. Reference type
            ex) pointer, object, ..
            = Store memory address in 'Heap'
    
    3) Why we need serialization?
        The memory space addresses used by each PC are completely different.
        Once the program ends, those addresses, used by a pointer,
        are no longer meaningful or useful.
        = 각 PC마다 사용하는 memory address는 전혀 다르다. 
        내가 다른PC로 전송한 Address data(0x00045523)은 무의미하다.
        In this case, we need the "Serialization".

        [ Role ]
        Convert a "reference type" object (stored in heap)
        into a "value type" representation (byte array: binary or string).

        [ TIP ]
        The storage location of the original object remains unchanged.
        Only its serialized form is created.
        = 형변환만 되는거지, 힙에 저장된 값이 스택으로 넘오는건 아니다.

    4) Deserialization
        Vice versa with serialization. 
        
        바이트 배열로부터 내용물을 읽어와 객체에 채우는 것.
        int타입으로 변환시킨 referenece타입을 다시 역 추적해서
        reference타입으로 변화시킨다.

    5) static method
        [ Why using 'static' for method? ]
        맴버 변수에 의존하지 않는 독립적인 함수의 경우
        Object를 만들지 않고도 사용 가능하기 때문에 (더 빠르고 효율적이다)
        static으로 만들어줘서 객체 없이 바로 호출 가능하도록 한다.

        [ Features ]
        1. Object생성 없이 호출 가능
        2. 불필요한 메모리 낭비 방지
        3. 멤버 변수를 사용하지 않는 독립적인 기능

(3) Function
    1. uintptr_t serialize(Data* ptr)
        Heap영역의 연속된 메모리 주소 값의 일부(직렬화된 데이터)를 반환.
    
        시스템에 따라 16진수(0x7ffee924c8f0)
               또는 10진수(140725931179472)로 출력될 수 있다.

    2. Data* deserialize(uintptr_t raw)
        직렬화된 포인터를 원래의 Data* 로 변환하는 함수.
        Data의 원본 데이터를 역직렬화하게 되며, 해당 구조체는 Heap 영역에 할당.

--------------------------------------------------------------------------------

[ ex02 ]
(1) In-short
    Down-casting
    = Parent class's (* || &) -> convert -> Child class's (* || &) wiht [dynamic_cast]

(2) Logic
    1. Make the inheritance structure (Base, A, B, C)
        Parent class: Base      // It only has 'virtual destructor'.
        Child class : A, B, C   // Inherit from the 'Base'.

    2. UP-casting
        [f] Base* generate();

        = Make the object randomly from the child class between (A, B, C).
        = return (Base *)

    3. Down-casting?
        [f] void identify(Base* p)  // based on pointer
        [f] void identify(Base& p)  // based on reference

        = Find whether 'p' belongs to any of classes (A, B, C).

--------------------------------------------------------------------------------