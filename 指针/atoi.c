//将字符串转换为数字
int MyAtoI(const char* str)
{
	int flag = 1;
	int num = 0;
	assert(str);
	while (*str)
	{
		if (isspace(*str))
		{
			str++;
		}
		else if (*str == '-' || *str == '+')
		{
			if (*str == '-') flag *= -1;
			str++;
		}
		else
		{
			while (isdigit(*str))
			{
				num = num * 10 + (int)(*str - '0');
				str++;
			}
			break;
		}
	}
	return num * flag;
}