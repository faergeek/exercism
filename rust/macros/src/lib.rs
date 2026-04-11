#[macro_export(local_inner_macros)]
macro_rules! hashmap {
    // comma-separated list of key-value pairs
    ( $( $k:expr => $v:expr),* ) => {
        {
            let mut hm = ::std::collections::HashMap::new();
            $(hm.insert($k, $v);)*
            hm
        }
    };

    // comma-terminated list of key-value pairs
    //
    // This is needed to account for a trailing comma,
    // but forbid passing just a comma without a single pair
    ( $( $k:expr => $v:expr,)+ ) => {
        hashmap!($($k => $v),+)
    };
}
