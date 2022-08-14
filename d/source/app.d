void fizzbuzz(const int n)()
{
	import std.stdio : writeln;
	import std.range : iota;

	static foreach (i; n.iota)
	{
		static if ((i % 3 == 0) && (i % 5 == 0))
			writeln("fizzbuzz");
		else static if (i % 3 == 0)
			writeln("fizz");
		else static if (i % 5 == 0)
			writeln("buzz");
		else
			writeln(i);
	}
}

void main()
{
	fizzbuzz!101();
}
