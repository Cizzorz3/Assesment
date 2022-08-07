void SWUART_init(uint32_t baudrate)
{
	UBRRL = 51;
    UCSRA &=!(1<<U2X);
    UCSRC |= (1<<UPM1);
    UCSRC &=! (0<<UPM0);
    UCSRC |=(1<<USBS);
    UCSRB |= (1<<TXEN);
    UCSRA &=!(1<<UDRE);
    UCSRB |= (1<<RXEN)
	
}
void SWUART_send(uint8_t data)
{
    
	while(!((UCSRA & (1<<UDRE)) >>UDRE));
	UDR = data;
	
}
void SWUART_recieve(uint8_t * data)
{
	while(!((UCSRA & (1<<UDRE)) >>UDRE));
	return UDR;
}
