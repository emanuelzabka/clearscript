
int fatorial(int x) does {
	if (x > 1) do {
		return x * fatorial(x - 1);
	} else {
		return 1;
	}
}

int soma(int x, int y) does {
	return x + y;
}

int subtrai(int x, int y) does {
	return x - y;
}

float soma5(int z) does {
	float asd;
	asd = z;
	return asd + 5.5;
}

string repete(string str1, int x) does {
	string result;
	int contador;
	contador = x;
	while (contador > 0) do
	{
		result = result ++ str1;
		contador = contador - 1;
	}
	return result;
}

main does {
	int a;
	int b;
	print("Fatorial: ", fatorial(4), "\n");
	a = 10;
	b = 5;
	print("Soma: ", soma(a, b), "\n");

	while (a > 0) do {
		print("A: ", a, "\n");
		a = a - 1;
	}
	
	print("Soma5: ", soma5(10), "\n");

	print("String " ++ "Concatenada\n");
	string outra;
	outra = "Outra";
	outra = outra ++ " String";
	print(outra ++ "\n");

	print("Repete: ", repete("abc", 2), "\n");
}
