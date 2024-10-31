#include "string.h"
#include "stdio.h"
#include "ads8353.h"

//32 clk dual mode cfr.b10 & b11 = 0
//ilk d�rt SDI biti operasyon modunu belirler
//ilk 16 bit ile register kontrol ediliyor
//16. sclk biti ile veri cikisi basliyor. msb first
//toplam 32 sclk d�sen kenar darbesi olmali ki paket onaylansin
//cs 0 yapildiginda adc calisiyor. sdo pin cikislari sifir oluyor ilk basta
//
//internette arduino �rnegine g�re mode = 1 yani cpol 0 cpha 1

//referans voltaji kart tarafindan belirleniyor bu y�zden registerda kapatilmali(CFR.B6 = 0)
//Vref 2.5 V
//cfr.b7 = 0 single ended input, cfr.b9 = 1 FSR i�in ?
//cfr.b4 = 0 output format binary
//��z�n�rl�k : 1 LSB = (FSR_ADC_x) / (2N) -> N = 16 bu modelde
//
//CFR 15:0
// 1 0 0 0 0 0 0 0 | 0 0 0 0 0 0 0 0
// 0x80
//default olarak CFR registerindaki t�m bitler sifir
void ads8353_init()
{

}

//ilgili cellin cs pini aktif edilecek (aktif low)
//GPIO_TypeDef *CS_Port, uint16_t CSPin
void ads8353_write_reg(uint8_t byte1, uint8_t byte2)
{
	uint8_t data[2];
	data[0] = byte1;
	data[1] = byte2;

}

//sdo_a ve sdo_b kanallarindan veri okumak i�in CS low yapildiktan sonra 32 clk cycle g�nderilmesi gerekiyor
//b�ylece �ikis pinlerinde veri okunabiliyor
//32 bit veri okunuyor bunun ilk 16si 0. sonraki 16 bit veri i�eriyor 32.bit yine 0
//MSB first yani 16.bit
uint16_t ads8353_read_adc(void)
{
	uint8_t rxData[2];  // Gelen veriyi depolamak i�in 2 byte'lik dizi
	uint8_t txData[2] = {0x00, 0x00};  // ADS8353'e g�nderilecek veriler

	
	uint16_t adcValue = (rxData[0] << 8) | rxData[1];

	return adcValue;
}