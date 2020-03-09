/*
	void erase(int index)
	{
		assert(index >= 0 && index < theSize);
		if (index == theSize - 1)
		{
			pop_back();
			return;
		}

		for (int i = index; i < theSize; i++)
			data[i] = data[i + 1];
		pop_back();
		return;
	}

	void erase(iterator itr)
	{
		assert(itr >= begin() && itr < end());

		if (itr == &data[theSize - 1])
		{
			pop_back();
			return;
		}

		iterator itr1 = itr;
		iterator itr2 = itr + 1;
		while (itr2 != end())
		{
			*itr1 = *itr2;
			++itr1;
			++itr2;
		}
		pop_back();
		return;
	}

	void insert(int index, int value)
	{
		if (index == theSize)
		{
			push_back(value);
			return;
		}
		assert(index >= 0 && index < theSize);
		push_back(back());
		for (int i = theSize; i >= index; i--)
			data[i] = data[i - 1];
		data[index] = value;
		return;
	}

	void insert(iterator itr, int value)
	{
		if (itr == end())
		{
			push_back(value);
			return;
		}
		assert(itr >= begin() && itr < end());
		push_back(back());
		iterator itr1 = end() - 2;
		iterator itr2 = end() - 1;
		while (itr1 >= itr)
		{
			*itr2 = *itr1;
			itr1--;
			itr2--;
		}
		*itr = value;
		return;
	}
*/
