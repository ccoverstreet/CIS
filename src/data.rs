pub fn tester() {
    println!("Hello from data module");
}

pub struct Element {
    pub symbol: &'static str,
    pub z: u32,
}

pub static PERIODIC_TABLE: [Element; 4] = [
    Element{symbol: "H", z: 1},
    Element{symbol: "He", z: 2},
    Element{symbol: "Li", z: 3},
    Element{symbol: "Be", z: 4},
];

