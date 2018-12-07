// Date: Fri, 07 Dec 2018 10:51:15 +0000
// Language: C# (Mono 4.6.2.0)
using System;
class Program
{
  static void Main(string[] args)
  {
    int n = int.Parse(Console.ReadLine());
    string[] input = Console.ReadLine().Split(' ');
    int cnt = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
      if (input[i] == "1")
        cnt++;
      else
        cnt = 0;
      ans = Math.Max(ans, cnt);
    }
    Console.WriteLine(ans + 1);
  }
}
