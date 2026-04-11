#[derive(Debug)]
pub struct Duration {
    pub seconds: f64,
}

impl From<u64> for Duration {
    fn from(s: u64) -> Self {
        Duration { seconds: s as f64 }
    }
}

pub trait Planet {
    fn ratio_to_earth() -> f64;

    fn years_during(d: &Duration) -> f64 {
        d.seconds / Self::ratio_to_earth()
    }
}

macro_rules! space_age_on {
    ($name:ident, $ratio_to_earth:expr) => {
        pub struct $name;
        impl Planet for $name {
            fn ratio_to_earth() -> f64 {
                $ratio_to_earth * 60.0 * 60.0 * 24.0 * 365.25
            }
        }
    };
}

space_age_on!(Mercury, 0.2408467);
space_age_on!(Venus, 0.61519726);
space_age_on!(Earth, 1.0);
space_age_on!(Mars, 1.8808158);
space_age_on!(Jupiter, 11.862615);
space_age_on!(Saturn, 29.447498);
space_age_on!(Uranus, 84.016846);
space_age_on!(Neptune, 164.79132);
