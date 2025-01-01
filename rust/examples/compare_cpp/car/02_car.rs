struct Car {
    brand: String,
    speed: u32,
}

impl Car {
    fn new(brand: &str, speed: u32) -> Self {
        Self {
            brand: brand.to_string(),
            speed,
        }
    }

    fn accelerate(&mut self, increment: u32) {
        self.speed += increment;
    }

    fn details(&self) -> String {
        format!("{} running at {} km/h", self.brand, self.speed)
    }
}

fn main() {
    let mut car = Car::new("Tesla", 60);
    car.accelerate(40);
    println!("{}", car.details());
}
