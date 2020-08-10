bool areKAnagrams(string a, string b, int k)
{
    if (a.length() != b.length())
        return false;
    int m[26] = {0};
    for (auto i = 0; i < a.length(); i++)
    {
        m[a[i] - 'a']++;
        m[b[i] - 'a']--;
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < 26; i++)
    {
        if (m[i] > 0)
            cnt1 += m[i];
        else
            cnt2 += m[i];
    }
    int ans = max(cnt1, abs(cnt2));
    if (ans <= k)
        return true;
    else
        return false;
}