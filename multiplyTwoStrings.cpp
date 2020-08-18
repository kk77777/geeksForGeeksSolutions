string multiplyStrings(string s1, string s2)
{
    int sign1 = 1, sign2 = 1;
    if (s1[0] == '-')
        sign1 = -1;
    if (s2[0] == '-')
        sign2 = -1;
    int sign = sign1 * sign2;
    int n = s1.size();
    int m = s2.size();
    if (n == 0 || m == 0)
        return "0";
    vector<int> v(n + m, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        if (s1[i] == '-')
            continue;
        for (int j = m - 1; j >= 0; j--)
        {
            if (s2[j] == '-')
                continue;

            int x = (s1[i] - '0') * (s2[j] - '0');
            int s = v[i + j + 1] + x;
            v[i + j] += s / 10;
            v[i + j + 1] = s % 10;
        }
    }
    string result = "";
    for (int i = 0; i < v.size(); i++)
    {
        if (result.length() != 0 || v[i] != 0)
        {
            result += to_string(v[i]);
        }
    }
    if (result.length() == 0)
        return "0";
    if (sign < 0)
        return ("-" + result);
    return result;
}