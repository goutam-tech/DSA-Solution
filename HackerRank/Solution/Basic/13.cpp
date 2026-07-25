/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s)
{
    int hour = stoi(s.substr(0, 2));
    string minutes = s.substr(3, 2);
    string second = s.substr(6, 2);
    string period = s.substr(8, 2);

    if (period == "AM" && hour == 12)
    {
        hour = 0;
    }

    if (period == "PM" && hour != 12)
    {
        hour += 12;
    }

    char buf[3];
    snprintf(buf, sizeof(buf), "%02d", hour);

    return string(buf) + ":" + minutes + ":" + second;
}