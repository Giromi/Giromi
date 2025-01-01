#![allow(unused)]

macro_rules! create_structs {
    ($($name:ident),*) => {
        $(
            /* 같은 모듈이라 pub 필요 없음 */
            struct $name {
                // pub value: i32,
                value: i32,
            }

            impl $name {
                /* 같은 모듈이라 pub 필요 없음 */
                fn new(value: i32) -> Self {
                    Self { value }
                }

                /* 이 함수 없으면 vaule 사용할 수 있네... */
                // fn value(&self) -> i32 {
                //     self.value
                // } 
            }
        )*
    };
}

mod another_module {
    /* 다른 모듈이라 pub 필요 */
    pub struct Yoo {
        value: i32,
    }

    impl Yoo {
        /* 다른 모듈이라 pub 필요 */
        pub fn new(value: i32) -> Self {
            Self { value }
        }
    }
}

struct Point {
    x: i32,
    y: i32,
}

create_structs!(Foo, Bar, Baz);

fn main() {
    let foo = Foo::new(42);
    let bar = Bar::new(100);
    let baz = Baz::new(7);

    /* new 키워드 없이도 생성 가능 */
    let p = Point { x: 10, y: 20 };                         // 같은 모듈 스택에 저장
    let p_heap = Box::new(Point { x: 10, y: 20 });          // 같은 모듈 힙에 저장
                                                            //
    /* new 키워드로 가독성 증진 */
    let yoo = another_module::Yoo::new(7);                  // 다른 모듈 스택에 저장
    let yoo_heap = Box::new(another_module::Yoo::new(7));   // 다른 모듈 힙에 저장

    // let baz = Baz{
    //     value: 7,
    // }

    println!("Point: ({}, {})", p.x, p.y);                                  // 같은 모듈 스택
    println!("Point: ({}, {})", p_heap.x, p_heap.y);                        // 같은 모듈 힙
    println!("Foo: {}, Bar: {}, Baz: {}", foo.value, bar.value, baz.value); // 같은 모듈
    println!("Yoo: {}", yoo.value);                                         // another module > error
    println!("Yoo: {}", yoo_heap.value);                                    // another module > error
}


/*
 * Rust의 매크로(macro_rules!)는 텍스트 치환이 아닌 구문적 수준에서의 코드 생성을 제공합니다. 이를 통해:
	1.	타입 안전성: 매크로가 생성한 코드는 컴파일러에 의해 검사됩니다.
	2.	유연성: 다양한 구문 패턴을 처리할 수 있습니다.
	3.	디버깅 용이성: 매크로로 확장된 코드는 실제 코드로 확인할 수 있습니다.
 */
