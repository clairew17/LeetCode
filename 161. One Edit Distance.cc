//161. One Edit Distance.cc

bool isOneEditDistance(string s, string t) 
{
	int m = s.size(), n = t.size();
	if(abs(m-n)>1)return false;
	if(m>n)return isOneEditDistance(t, s);

	//m == n-1 || m == n

	bool mismatch = false;
	for(int i=0;i<m;i++)
	{
		if(s[i] != t[i])
		{
			if(m==n)s[i]=t[i];//m==n
			else s.insert(i, 1, t[i]);//m==n-1
			mismatch = true;
			break;
		}
	}

	return (mismatch == true && s==t) || (mismatch==false && n-m==1);
}
