#include "mini_caps.h"
#include <string.h>

const uint8_t basicFont[96][8] =
{
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x00,0x5F,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x00,0x07,0x00,0x07,0x00,0x00,0x00},
  {0x00,0x14,0x7F,0x14,0x7F,0x14,0x00,0x00},
  {0x00,0x24,0x2A,0x7F,0x2A,0x12,0x00,0x00},
  {0x00,0x23,0x13,0x08,0x64,0x62,0x00,0x00},
  {0x00,0x36,0x49,0x55,0x22,0x50,0x00,0x00},
  {0x00,0x00,0x05,0x03,0x00,0x00,0x00,0x00},
  {0x00,0x1C,0x22,0x41,0x00,0x00,0x00,0x00},
  {0x00,0x41,0x22,0x1C,0x00,0x00,0x00,0x00},
  {0x00,0x08,0x2A,0x1C,0x2A,0x08,0x00,0x00},
  {0x00,0x08,0x08,0x3E,0x08,0x08,0x00,0x00},
  {0x00,0xA0,0x60,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x08,0x08,0x08,0x08,0x08,0x00,0x00},
  {0x00,0x60,0x60,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x20,0x10,0x08,0x04,0x02,0x00,0x00},
  {0x00,0x3E,0x51,0x49,0x45,0x3E,0x00,0x00},
  {0x00,0x00,0x42,0x7F,0x40,0x00,0x00,0x00},
  {0x00,0x62,0x51,0x49,0x49,0x46,0x00,0x00},
  {0x00,0x22,0x41,0x49,0x49,0x36,0x00,0x00},
  {0x00,0x18,0x14,0x12,0x7F,0x10,0x00,0x00},
  {0x00,0x27,0x45,0x45,0x45,0x39,0x00,0x00},
  {0x00,0x3C,0x4A,0x49,0x49,0x30,0x00,0x00},
  {0x00,0x01,0x71,0x09,0x05,0x03,0x00,0x00},
  {0x00,0x36,0x49,0x49,0x49,0x36,0x00,0x00},
  {0x00,0x06,0x49,0x49,0x29,0x1E,0x00,0x00},
  {0x00,0x00,0x36,0x36,0x00,0x00,0x00,0x00},
  {0x00,0x00,0xAC,0x6C,0x00,0x00,0x00,0x00},
  {0x00,0x08,0x14,0x22,0x41,0x00,0x00,0x00},
  {0x00,0x14,0x14,0x14,0x14,0x14,0x00,0x00},
  {0x00,0x41,0x22,0x14,0x08,0x00,0x00,0x00},
  {0x00,0x02,0x01,0x51,0x09,0x06,0x00,0x00},
  {0x00,0x32,0x49,0x79,0x41,0x3E,0x00,0x00},
  {0x00,0x7E,0x09,0x09,0x09,0x7E,0x00,0x00},
  {0x00,0x7F,0x49,0x49,0x49,0x36,0x00,0x00},
  {0x00,0x3E,0x41,0x41,0x41,0x22,0x00,0x00},
  {0x00,0x7F,0x41,0x41,0x22,0x1C,0x00,0x00},
  {0x00,0x7F,0x49,0x49,0x49,0x41,0x00,0x00},
  {0x00,0x7F,0x09,0x09,0x09,0x01,0x00,0x00},
  {0x00,0x3E,0x41,0x41,0x51,0x72,0x00,0x00},
  {0x00,0x7F,0x08,0x08,0x08,0x7F,0x00,0x00},
  {0x00,0x41,0x7F,0x41,0x00,0x00,0x00,0x00},
  {0x00,0x20,0x40,0x41,0x3F,0x01,0x00,0x00},
  {0x00,0x7F,0x08,0x14,0x22,0x41,0x00,0x00},
  {0x00,0x7F,0x40,0x40,0x40,0x40,0x00,0x00},
  {0x00,0x7F,0x02,0x0C,0x02,0x7F,0x00,0x00},
  {0x00,0x7F,0x04,0x08,0x10,0x7F,0x00,0x00},
  {0x00,0x3E,0x41,0x41,0x41,0x3E,0x00,0x00},
  {0x00,0x7F,0x09,0x09,0x09,0x06,0x00,0x00},
  {0x00,0x3E,0x41,0x51,0x21,0x5E,0x00,0x00},
  {0x00,0x7F,0x09,0x19,0x29,0x46,0x00,0x00},
  {0x00,0x26,0x49,0x49,0x49,0x32,0x00,0x00},
  {0x00,0x01,0x01,0x7F,0x01,0x01,0x00,0x00},
  {0x00,0x3F,0x40,0x40,0x40,0x3F,0x00,0x00},
  {0x00,0x1F,0x20,0x40,0x20,0x1F,0x00,0x00},
  {0x00,0x3F,0x40,0x38,0x40,0x3F,0x00,0x00},
  {0x00,0x63,0x14,0x08,0x14,0x63,0x00,0x00},
  {0x00,0x03,0x04,0x78,0x04,0x03,0x00,0x00},
  {0x00,0x61,0x51,0x49,0x45,0x43,0x00,0x00},
  {0x00,0x7F,0x41,0x41,0x00,0x00,0x00,0x00},
  {0x00,0x02,0x04,0x08,0x10,0x20,0x00,0x00},
  {0x00,0x41,0x41,0x7F,0x00,0x00,0x00,0x00},
  {0x00,0x04,0x02,0x01,0x02,0x04,0x00,0x00},
  {0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00},
  {0x00,0x01,0x02,0x04,0x00,0x00,0x00,0x00},
  {0x00,0x20,0x54,0x54,0x54,0x78,0x00,0x00},
  {0x00,0x7F,0x48,0x44,0x44,0x38,0x00,0x00},
  {0x00,0x38,0x44,0x44,0x28,0x00,0x00,0x00},
  {0x00,0x38,0x44,0x44,0x48,0x7F,0x00,0x00},
  {0x00,0x38,0x54,0x54,0x54,0x18,0x00,0x00},
  {0x00,0x08,0x7E,0x09,0x02,0x00,0x00,0x00},
  {0x00,0x18,0xA4,0xA4,0xA4,0x7C,0x00,0x00},
  {0x00,0x7F,0x08,0x04,0x04,0x78,0x00,0x00},
  {0x00,0x00,0x7D,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x80,0x84,0x7D,0x00,0x00,0x00,0x00},
  {0x00,0x7F,0x10,0x28,0x44,0x00,0x00,0x00},
  {0x00,0x41,0x7F,0x40,0x00,0x00,0x00,0x00},
  {0x00,0x7C,0x04,0x18,0x04,0x78,0x00,0x00},
  {0x00,0x7C,0x08,0x04,0x7C,0x00,0x00,0x00},
  {0x00,0x38,0x44,0x44,0x38,0x00,0x00,0x00},
  {0x00,0xFC,0x24,0x24,0x18,0x00,0x00,0x00},
  {0x00,0x18,0x24,0x24,0xFC,0x00,0x00,0x00},
  {0x00,0x00,0x7C,0x08,0x04,0x00,0x00,0x00},
  {0x00,0x48,0x54,0x54,0x24,0x00,0x00,0x00},
  {0x00,0x04,0x7F,0x44,0x00,0x00,0x00,0x00},
  {0x00,0x3C,0x40,0x40,0x7C,0x00,0x00,0x00},
  {0x00,0x1C,0x20,0x40,0x20,0x1C,0x00,0x00},
  {0x00,0x3C,0x40,0x30,0x40,0x3C,0x00,0x00},
  {0x00,0x44,0x28,0x10,0x28,0x44,0x00,0x00},
  {0x00,0x1C,0xA0,0xA0,0x7C,0x00,0x00,0x00},
  {0x00,0x44,0x64,0x54,0x4C,0x44,0x00,0x00},
  {0x00,0x08,0x36,0x41,0x00,0x00,0x00,0x00},
  {0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x41,0x36,0x08,0x00,0x00,0x00,0x00},
  {0x00,0x02,0x01,0x01,0x02,0x01,0x00,0x00},
  {0x00,0x02,0x05,0x05,0x02,0x00,0x00,0x00} 
};


uint8_t     history[SIZE_HISTORY];  // 
uint32_t    offset_screen;
uint32_t    offset_screen_max = SIZE_HISTORY >> 7;
uint32_t    line_screen;            // la c'est le numerot de ligne qu'on affiche
uint32_t    curs_head;
uint32_t    curs_over_head;

uint8_t     buff_str[128];

void    init_mini_caps()
{
    uint16_t    i;
    
    line_screen = 0;
    curs_head = 0;
    curs_over_head = 0;
    for (i = 0; i < SIZE_HISTORY; i++)
        history[i] = 0;
}

void    curs_incr()
{
    // une ligne = 16 * 8 = 2^(4 + 3))
    curs_head += 8;  // une font de charactere fait 8 octet en memoir
    line_screen = curs_head >> 7;
    
    if (curs_head >= SIZE_HISTORY)
    {
        curs_head %= SIZE_HISTORY;
        curs_over_head = 1;
    }
}

void    putendl()
{
    uint8_t i;
    uint8_t size;
    
    size = (CHAR_BY_LINE - (curs_head / 8) % CHAR_BY_LINE);
 //   curs_pos += size;
    for (i = 0; i < size; i++)
        my_putchar(' ');
}

void    puttab()
{
    uint8_t i;
    uint8_t size;
    
    size = (TAB_SIZE - (curs_head / 8) % TAB_SIZE);
    for (i = 0; i < size; i++)
        my_putchar(' ');
}

void    add_one_char()
{
}

void    my_putchar2(int8_t c)
{
    uint64_t    none = 0xFFFFFFFFFFFFFFF;
    int8_t      id = (int8_t)c;
    
    if (c == '\n')
        return (putendl());
    if (c == '\t')
        return (puttab());
    if (c >= ' ' && c <= '~')
        send_oled_data((uint8_t*)&(basicFont[c - ' '][0]), 8);//send_oled_data((uint8_t*)(&(basicFont[c - ' '][0])), 8);
    else
        send_oled_data((uint8_t*)&(none), 8);//send_oled_data((uint8_t*)(&none), 8);
    curs_incr();
//    wait(2);
}
void    my_putstr2(int8_t *str)
{
    uint16_t    i;
    
    i = 0;
    while (str[i])
    {
        my_putchar2(str[i]);
        i++;
    }
//    print_screen();
}


void    my_putchar(int8_t c)
{
    uint64_t    none = 0xFFFFFFFFFFFFFFF;
    int8_t      id = (int8_t)c;
    
    if (c == '\n')
        return (putendl());
    if (c == '\t')
        return (puttab());
    if (c >= ' ' && c <= '~')
        memmove(history + curs_head, &(basicFont[c - ' '][0]), 8);//send_oled_data((uint8_t*)(&(basicFont[c - ' '][0])), 8);
    else
        memmove(history + curs_head, &(none), 8);//send_oled_data((uint8_t*)(&none), 8);
    curs_incr();
    wait(2);
}

void    my_putstr(int8_t *str)
{
    uint16_t    i;
    
    i = 0;
    while (str[i])
    {
        my_putchar(str[i]);
        i++;
        print_screen();
    }

}

void    my_putnbr(int32_t nbr)
{
    if (nbr < -2147483647)
        return (my_putstr("-2147483648")); 
    if (nbr < 0)
        return (my_putchar('-'), my_putnbr(-nbr));
    if (nbr < 10)
        return (my_putchar('0' + nbr));
    my_putnbr(nbr / 10);
    my_putchar('0' + (nbr % 10));
}

void    putnbr_endl(int32_t nbr)
{
    my_putnbr(nbr);
    my_putchar('\n');
}

void    print_screen()
{
    uint32_t    beg;
    uint32_t    size;
    uint32_t    curs_aff;
    
    curs_aff = (curs_head - offset_screen) % SIZE_HISTORY;
    if (curs_aff < (OLED_SIZE) && curs_over_head)
    {
 //       wait(10);
        beg = (SIZE_HISTORY - OLED_SIZE + ((curs_aff >> 7) << 7));
        size = (SIZE_HISTORY - beg);
        send_oled_data(history + beg, size);
        size = OLED_SIZE - size;
        send_oled_data(history, size);
        return ;
        // cas spetile de jointure
    }
    else if (curs_aff < (OLED_SIZE) && !curs_over_head)
        beg = 0;
    else
        beg = (line_screen - 7) << 7;
    send_oled_data(history + beg, OLED_SIZE);
}

/*
 * on va faire un tableau de 256x16x8 ==> 256 ligne de 16 caractere de 8 octet
 * quand on fait appele a send_data on ecrit dans le tableau dont on garde:
 *      -curseur de tete (ligne)
 *      -curseur dans la ligne
 * 
 * quand on va au bout du buffer on re ecrit au debut de la memoir
 * mais pour l'affichage ca ne change rien
 * 
 * fonction:
 * >> putchar, putstr, putnbr, 
 * 
 * on rajoute au buffer
 * on afficher le buffer a un sertain offset
 * on actualise le buffer                   : apres chaque putstr, ou equivalent
 * 
 * donc pour afficher une ligne a un autre endroi il faut 
 * 
 */