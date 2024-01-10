
void LCDinit()
{

	cmd(0x01);
	cmd(0x38);
	cmd(0x0E);
}
void cmd(unsigned char y)
{
	 HAL_GPIO_WritePin(GPIOA, RS_Pin,0);
	 HAL_GPIO_WritePin(GPIOB, D7_Pin,(y & 0x80));
	 HAL_GPIO_WritePin(GPIOB, D6_Pin,(y & 0x40));
	 HAL_GPIO_WritePin(GPIOB, D5_Pin,(y & 0x20));
	 HAL_GPIO_WritePin(GPIOB, D4_Pin,(y & 0x10));
	 HAL_GPIO_WritePin(GPIOB, D3_Pin,(y & 0x08));
	 HAL_GPIO_WritePin(GPIOB, D2_Pin,(y & 0x04));
	 HAL_GPIO_WritePin(GPIOC, D1_Pin,(y & 0x02));
	 HAL_GPIO_WritePin(GPIOC, D0_Pin,(y & 0x01));
	 HAL_GPIO_WritePin(GPIOA, EN_Pin,1);
	 HAL_Delay(20);
	 HAL_GPIO_WritePin(GPIOA, EN_Pin,0);
	 HAL_Delay(20);

}
void input(unsigned char *x)
{
	while(*x)
	{
		Data(*x++);
		HAL_Delay(20);
	}
}
void Data(unsigned char z)
{
	     HAL_GPIO_WritePin(GPIOA, RS_Pin,1);
		 HAL_GPIO_WritePin(GPIOB, D7_Pin,(z & 0x80));
		 HAL_GPIO_WritePin(GPIOB, D6_Pin,(z & 0x40));
		 HAL_GPIO_WritePin(GPIOB, D5_Pin,(z & 0x20));
		 HAL_GPIO_WritePin(GPIOB, D4_Pin,(z & 0x10));
		 HAL_GPIO_WritePin(GPIOB, D3_Pin,(z & 0x08));
		 HAL_GPIO_WritePin(GPIOB, D2_Pin,(z & 0x04));
		 HAL_GPIO_WritePin(GPIOC, D1_Pin,(z & 0x02));
		 HAL_GPIO_WritePin(GPIOC, D0_Pin,(z & 0x01));
		 HAL_GPIO_WritePin(GPIOA, EN_Pin,1);
		 HAL_Delay(20);
		 HAL_GPIO_WritePin(GPIOA, EN_Pin,0);
		 HAL_Delay(20);
}
void Numericdata(unsigned int a)
{
	Data(((a%1000)/100)+0x30);
	Data(((a%100)/10)+0x30);
	Data(((a%10))+0x30);
}
