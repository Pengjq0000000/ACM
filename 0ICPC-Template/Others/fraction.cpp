struct fraction
{
	ll a,b;
	fraction() {};
	fraction(ll x,ll y) :a(x),b(y) {};
	fraction friend operator + (fraction x,fraction y)
	{
		if(x.a==0) return y;
		else if(y.a==0) return x;
		fraction z;
		z.a=x.a*y.b+x.b*y.a;
		z.b=x.b*y.b;
		ll g=__gcd(z.a,z.b);
		z.a/=g; z.b/=g;
		return z;
	}
	fraction friend operator * (fraction x,fraction y)
	{
		fraction z;
		z.a=x.a*y.a;
		z.b=x.b*y.b;
		if(z.a==0)
		{
			z.b=1;
			return z;
		}
		ll g=__gcd(z.a,z.b);
		z.a/=g; z.b/=g;
		return z;
	}
	fraction friend operator * (fraction x,ll y)
	{
		fraction z;
		z.a=x.a*y;
		z.b=x.b;
		if(z.a==0)
		{
			z.b=1;
			return z;
		}
		ll g=__gcd(z.a,z.b);
		z.a/=g; z.b/=g;
		return z;
	}
	fraction friend operator / (fraction x,ll y)
	{
		fraction z;
		z.a=x.a;
		z.b=x.b*y;
		if(z.a==0)
		{
			z.b=1;
			return z;
		}
		ll g=__gcd(z.a,z.b);
		z.a/=g; z.b/=g;
		return z;
	}
};


