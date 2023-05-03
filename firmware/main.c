#include <stdint.h>

#include <avr/io.h>

int main (void)
{
	uint8_t act, old, c = 0;

	DDRB  = 0x02;
	PORTB = 0x00;

	old = PORTB & 1;

	while (1)
	{
		act = PORTB & 1;
		if (act != old)
		{
			old = act;

			if (act)
			{
				c++;
				if ((PORTB & 4) && (c & 1))
					continue;

				PORTB |= 2;
			}
			else
				PORTB &= ~2;
		}
	}

	return 0;
}
