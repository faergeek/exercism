#[derive(Debug)]
pub struct Duration {
    pub seconds: u64,
}

impl From<u64> for Duration {
    fn from(seconds: u64) -> Self {
        Duration { seconds }
    }
}

const EARTH_YEAR_SECONDS: f64 = 60.0 * 60.0 * 24.0 * 365.25;
const MERCURY_YEAR_SECONDS: f64 = EARTH_YEAR_SECONDS * 0.2408467;
const VENUS_YEAR_SECONDS: f64 = EARTH_YEAR_SECONDS * 0.61519726;
const MARS_YEAR_SECONDS: f64 = EARTH_YEAR_SECONDS * 1.8808158;
const JUPITER_YEAR_SECONDS: f64 = EARTH_YEAR_SECONDS * 11.862615;
const SATURN_YEAR_SECONDS: f64 = EARTH_YEAR_SECONDS * 29.447498;
const URANUS_YEAR_SECONDS: f64 = EARTH_YEAR_SECONDS * 84.016846;
const NEPTUNE_YEAR_SECONDS: f64 = EARTH_YEAR_SECONDS * 164.79132;

pub trait Planet {
    fn seconds_per_year() -> f64;

    fn years_during(d: &Duration) -> f64 {
        d.seconds as f64 / Self::seconds_per_year()
    }
}

pub struct Mercury;
pub struct Venus;
pub struct Earth;
pub struct Mars;
pub struct Jupiter;
pub struct Saturn;
pub struct Uranus;
pub struct Neptune;

impl Planet for Mercury {
    fn seconds_per_year() -> f64 {
        MERCURY_YEAR_SECONDS
    }
}

impl Planet for Venus {
    fn seconds_per_year() -> f64 {
        VENUS_YEAR_SECONDS
    }
}

impl Planet for Earth {
    fn seconds_per_year() -> f64 {
        EARTH_YEAR_SECONDS
    }
}

impl Planet for Mars {
    fn seconds_per_year() -> f64 {
        MARS_YEAR_SECONDS
    }
}

impl Planet for Jupiter {
    fn seconds_per_year() -> f64 {
        JUPITER_YEAR_SECONDS
    }
}

impl Planet for Saturn {
    fn seconds_per_year() -> f64 {
        SATURN_YEAR_SECONDS
    }
}

impl Planet for Uranus {
    fn seconds_per_year() -> f64 {
        URANUS_YEAR_SECONDS
    }
}

impl Planet for Neptune {
    fn seconds_per_year() -> f64 {
        NEPTUNE_YEAR_SECONDS
    }
}
