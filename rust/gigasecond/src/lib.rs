use std::time::Duration;
use time::PrimitiveDateTime as DateTime;

pub fn after(start: DateTime) -> DateTime {
    return start + Duration::from_secs(10_u64.pow(9));
}
