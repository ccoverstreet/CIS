mod data;

fn main() {
    println!("Hello, world!");
    data::tester();

    for elem in data::PERIODIC_TABLE.iter() {
        println!("{}, {}", elem.symbol, elem.z);
    }
}
