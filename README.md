# Currency Converter (C++)

A simple command-line currency converter built in C++.

## Features

* Convert between multiple currencies:

  * USD (US Dollar)
  * EUR (Euro)
  * JPY (Japanese Yen)
  * RUPEE (Indian Rupee)
  * LEKE (Albanian Lek)
  * POUND (British Pound)

* Fast currency lookup using `unordered_map`

* User-friendly command-line interface

* Input validation for unsupported currencies

* Supports repeated conversions in a single session

## Technologies Used

* C++
* STL `unordered_map`
* Functions
* Structs

## How It Works

The program stores exchange rates in a hash map using currency pairs such as:

USD->EUR

EUR->JPY

POUND->USD

The user selects a source currency, target currency, and amount. The converter then calculates and displays the converted value.

## Example

Enter the currency you want to convert from: USD

Enter the currency you want to convert to: EUR

Enter the amount: 100

Converted amount: 85

## Future Improvements

* Real-time exchange rates using an API
* Support for more currencies
* Case-insensitive input
* Conversion history
* Graphical User Interface (GUI)

## Author

Harbin Gaming
