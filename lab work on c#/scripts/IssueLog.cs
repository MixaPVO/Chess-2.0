public sealed class IssueLog : IDisposable
{
public int testNumber = 0;
private readonly string _title;
public IssueLog(string title)
{
_title = title;
Console.WriteLine($"[+] журнал открыт: {_title}");
}
public void Write(string line) => Console.WriteLine($" {line}");
public void Dispose() => Console.WriteLine($"[-] журнал закрыт: {_title}");
}