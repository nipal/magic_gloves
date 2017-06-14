/*
int8_t  txt_karimu[13][32] = {
    {"################"},
    {"Who is it?\n"},
    {"OWW it's the:\n"},
    {" GRAND KARIMU\n\n"},
    {"I'm so proud to\n"},
    {"meet you.\n"},
    {"I heard about\n"},
    {"your wining on:\n"},
    {"################\n"},
    {"Street fighter 5\n"},
    {"################\n"},
    {"Well...\n"},
    {"\n\n\tBY\n\n"}};

void    super_karim()
{
    uint8_t i;
    
    for (i = 0; i < 13; i++)
    {
        my_putstr(txt_karimu[i]);
    }
}    

void tick_tick()
{
    int i = 0;
    int j = 0;
    uint8_t     data[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    uint32_t    test;
    
    
    test = 0xFFFFFFFF;
//    oledClear();
//    oledUpdate();
    while (1)
    {
 //       wait(10);
        LED1 = ~GET_LED1;
        
        if (j >= 96)
            j = 0;
        //send_oled_data((uint8_t*)&(basicFont[j][0]), 8);
        //my_putstr(" # Je suis un LAPIN!!! #");
        my_putstr("## Lapin est le plus beau ##");
        //        LED2 = buff_is_empty();
  //      oledUpdate();
        i++;
        j++;
        //LED1 = ~GET_LED1;
    }

}

void test_putnbr()
{
    putnbr_endl(42);
    putnbr_endl(666);
    putnbr_endl(-12);
    putnbr_endl(0);
    putnbr_endl(-2147483647);
//    putnbr_endl(2147483648);
    putnbr_endl(-42);
}

void test_sprintf()
{
    int8_t  buff[50];
    char toto[10] = "Lapin";
    float   b = 8.987;
    int32_t   c = 988;
    uint16_t    ret;
    
    ret = sprintf(buff, "Bonjour %s je te trouve tres:\n  %f\n%d\n", toto, b, c);
    buff[ret] = 0;
    my_putstr(buff);
}

void    test_scroll_str()
{
    uint8_t time = 1;
    
        wait(time); my_putstr(".\n");
        wait(time); my_putstr("..\n");
        wait(time); my_putstr("...\n");
        wait(time); my_putstr("....\n");
        wait(time); my_putstr("...\n");
        wait(time); my_putstr("..\n");
        wait(time); my_putstr(".\n");
        wait(time); my_putstr("\n");


}

void    test_scrol_nbr()
{
    float       i;
    float       f;
    float       r;
    int8_t      buff[16];

    sprintf(buff, "42");
    my_putstr(buff);
}

void    rambow_led(void)
{
    uint8_t time = 10;
        
    wait(time); LED1 = 1;
    wait(time); LED1 = 0;
    wait(time); LED2 = 1;
    wait(time); LED2 = 0;
    wait(time); LED3 = 1;
    wait(time); LED3 = 0;
}

//    init_mini_caps();
//    init_oled();
 //   init_i2c_5();

*/