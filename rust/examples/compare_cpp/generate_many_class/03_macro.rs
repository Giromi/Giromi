#![allow(unused)]

macro_rules! create_structs {
    ($($name:ident),*) => {
        $(
            struct $name {
                value: i32,
            }

            impl $name {
                fn new(value: i32) -> Self {
                    Self { value }
                }
            }
        )*
    };
}

create_structs!(Foo, Bar, Baz);

fn main() {
    let foo = Foo::new(42);
    let bar = Bar::new(100);
    let baz = Baz::new(7);

    println!("Foo: {}, Bar: {}, Baz: {}", foo.value, bar.value, baz.value);
}


/*
 * Rust의 매크로(macro_rules!)는 텍스트 치환이 아닌 구문적 수준에서의 코드 생성을 제공합니다. 이를 통해:
	1.	타입 안전성: 매크로가 생성한 코드는 컴파일러에 의해 검사됩니다.
	2.	유연성: 다양한 구문 패턴을 처리할 수 있습니다.
	3.	디버깅 용이성: 매크로로 확장된 코드는 실제 코드로 확인할 수 있습니다.
 */
