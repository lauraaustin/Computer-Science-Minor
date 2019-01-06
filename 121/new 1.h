double r ;
	double h;
	double A;
	double PI;
	double a;
	double p;
	
	//num assign
	r = 7; //radius
	h = (14 + sqrt(14-(chord*chord)) )/2;
	A = (r*r)*acos((r-h)/r)-(r-h)*sqrt(2*r*h-(h*h));
	PI = 3.14159;
	a = PI*r*r;
	p = (A/a)*100;
	
	cin >> p;
	cout << "That cut leaves " << p << "% of the pizza.";
	return 0;
}