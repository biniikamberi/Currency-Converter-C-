#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

string upperCase(string str){
    for(int i = 0; i < str.length(); i++){
        str[i] = toupper(str[i]);
    }
    return str;
}

typedef struct {
    unordered_map<string, double> exchangeRate;
    void addExchangeRate(const string& from, const string& to, double rate) {
    string fromUpper = upperCase(from);
    string toUpper = upperCase(to);
    exchangeRate[fromUpper + "->" + toUpper] = rate;
}

    double convert(string from,string to, double amount){
        from = upperCase(from);
        to = upperCase(to);

        string key = from + "->" + to;
        if(exchangeRate.find(key) != exchangeRate.end()){
            return amount * exchangeRate[key];
        } else {
            cout << "Exchange rate not found for " << from << " to " << to << endl;
            return -1; // Indicating error
        }
    }

}CurrencyConverter;
void Rates(CurrencyConverter& convert){
    convert.addExchangeRate("USD", "EUR", 0.85);
    convert.addExchangeRate("EUR", "USD", 1.18);
    convert.addExchangeRate("USD", "JPY", 110.0);
    convert.addExchangeRate("JPY", "USD", 0.0091);
    convert.addExchangeRate("RUPEE", "USD", 0.013);
    convert.addExchangeRate("USD", "RUPEE", 75.0);
    convert.addExchangeRate("RUPEE", "EUR", 0.011);
    convert.addExchangeRate("EUR", "RUPEE", 90.0);
    convert.addExchangeRate("RUPEE", "JPY", 1.5);
    convert.addExchangeRate("JPY", "RUPEE", 0.67);
    convert.addExchangeRate("EUR", "JPY", 129.0);
    convert.addExchangeRate("JPY", "EUR", 0.0077);
    convert.addExchangeRate("LEKE", "USD", 0.0095);
    convert.addExchangeRate("USD", "LEKE", 105.0);
    convert.addExchangeRate("LEKE", "EUR", 0.008);
    convert.addExchangeRate("EUR", "LEKE", 120.0);
    convert.addExchangeRate("LEKE", "JPY", 1.1);
    convert.addExchangeRate("JPY", "LEKE", 0.91);
    convert.addExchangeRate("LEKE", "RUPEE", 0.012);
    convert.addExchangeRate("RUPEE", "LEKE", 83.0);
    convert.addExchangeRate("POUND", "USD", 1.39);
    convert.addExchangeRate("USD", "POUND", 0.72);
    convert.addExchangeRate("POUND", "EUR", 1.17);
    convert.addExchangeRate("EUR", "POUND", 0.85);
    convert.addExchangeRate("POUND", "JPY", 153.0);
    convert.addExchangeRate("JPY", "POUND", 0.0065);
    convert.addExchangeRate("POUND", "RUPEE", 100.0);
    convert.addExchangeRate("RUPEE", "POUND", 0.01);
    convert.addExchangeRate("POUND", "LEKE", 140.0);
    convert.addExchangeRate("LEKE", "POUND", 0.0071);
}

int main(){
    Retry:
    CurrencyConverter convert;
    Rates(convert);
    string from;
    string to;
    double amount;
    cout << "Enter the currency you want to convert from (USD, EUR, JPY, RUPEE, LEKE, POUND): ";
    cin >> from;
    if(from != "USD" && from != "EUR" && from != "JPY" && from != "RUPEE" && from != "LEKE" && from != "POUND"){
        cout << "Invalid currency. Please enter a valid currency." << endl;
        return 0;
    }
    cout << "Enter the currency you want to convert to: ";
    cin >> to;
    if(to != "USD" && to != "EUR" && to != "JPY" && to != "RUPEE" && to != "LEKE" && to != "POUND"){
        cout << "Invalid currency. Please enter a valid currency." << endl;
        return 0;
    }
    cout << "Enter the amount: ";
    cin >> amount;
    double result = convert.convert(from, to, amount);
    if(result != -1){
        cout << "Converted amount: " << result << endl;
    }
    char ch;
    cout << "Do you want to retry the conversion program? (y/n): ";
    cin >> ch;
    if(ch == 'y' || ch == 'Y'){
        goto Retry;
    }else    
    return 0;
}