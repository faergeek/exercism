#include "say.h"
#include <stdexcept>

namespace say {

static std::string unit_words[] = {"zero", "one", "two",   "three", "four",
                                   "five", "six", "seven", "eight", "nine"};

static std::string teen_words[] = {"eleven", "twelve", "thirteen", "fourteen",
                                   "fifteen"};

static std::string ten_words[] = {"twenty", "thirty",  "forty",  "fifty",
                                  "sixty",  "seventy", "eighty", "ninety"};

std::string in_english(long n) {
  if (0 > n || n >= 1000000000000) {
    throw std::domain_error("input is not allowed to be negative");
  }

  if (n < 10) {
    return unit_words[n];
  }

  if (n == 10) {
    return "ten";
  }

  if (n < 20) {
    const size_t remainder = n % 10 - 1;

    if (remainder < sizeof(teen_words) / sizeof(teen_words[0])) {
      return teen_words[remainder];
    }

    return unit_words[remainder] + "teen";
  }

  if (n < 100) {
    ldiv_t divided = ldiv(n, 10);
    std::string word = ten_words[divided.quot - 2];

    return divided.rem == 0 ? word : word + "-" + in_english(divided.rem);
  }

  long denominator;
  std::string suffix;
  if (n < 1000) {
    denominator = 100;
    suffix = " hundred";
  } else if (n < 1000000) {
    denominator = 1000;
    suffix = " thousand";
  } else if (n < 1000000000) {
    denominator = 1000000;
    suffix = " million";
  } else {
    denominator = 1000000000;
    suffix = " billion";
  }

  ldiv_t divided = ldiv(n, denominator);
  std::string word = in_english(divided.quot) + suffix;

  return divided.rem == 0 ? word : word + " " + in_english(divided.rem);
}

} // namespace say
