class Program{

	int i;
	int x[2];

	int main(){
		int a, b;
		b = 5;

		if(b != 5){
			i = 9;
		}
		else {
			i = 2;
		}
		a = b + i;

		callout("printf", "%d\n", a);

		if(i == 2){
			b = 35;
		}

		a = a + b;
		callout("printf", "%d\n", a);

		x[1] = 6;
		if(x[1] == 6){
			x[1] = a - a + 20;
		}
		callout("printf", "%d\n", x[1]);

		if(1){
			callout("printf", "%s\n", "Working The End");
		}
	}
}
