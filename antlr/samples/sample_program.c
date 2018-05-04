/// Functions
int foo_int(void) 
{

}

int foo_int(int bar) 
{

}

void foo_void(void)
{

}

bool foo_bool(void)
{

}

bool foo_bool(bool bar)
{

}

char foo_char(void)
{

}

char foo_char(char bar)
{

}

uint32_t foo_uint32_t(void)
{

}

uint32_t foo_uint32_t(uint32_t bar)
{

}

/// Arithmetic

void arithmetic(void)
{
    static uint32_t x = 0;

    x += 0x1234;
    x -= 0x1234;
    x /= 0x1234;
    x *= 0x1234;
    x ^= 0x1234;
    x ~= 0x1234;
    x |= 0x1234;
    x &= 0x1234;

    uint32_t y = 0xFFFFFFFF;

    y = x + 9999;
    y = x - 9999;
    y = x / 9999;
    y = x * 9999;
    y = x ^ 9999;
    y = x | 9999;
    y = x & 9999;

    const uint32_t z  = ((x & (1 << 0)) >> (31 - 0)) |
                        ((x & (1 << 1)) >> (31 - 1)) |
                        ((x & (1 << 2)) >> (31 - 2)) |
                        ((x & (1 << 3)) >> (31 - 3)) |
                        ((x & (1 << 4)) >> (31 - 4)) |
                        ((x & (1 << 5)) >> (31 - 4));
}

/// Loops

void loops(void)
{
    for (uint32_t i = 0; i < 0xFFFF; i++)
    {
        if (i < 0xFFFF)
        {
            continue;
        }
        else
        {
            break;
        }
    }

    int32_t i = 0xFFFFFFFE;
    while (--i > 0)
    {
        if (i % 10000 == 1)
        {
            break;
        }
    }
}

/// Conditions

void conditions(void)
{
    const bool a = false;
    const bool b = true;
    const bool c = false;
    const bool d = true;
    const bool e = false;
    const bool f = true;

    const uint32_t vector = (a & 1) << 0 |
                            (b & 1) << 1 |
                            (c & 1) << 2 |
                            (d & 1) << 3 |
                            (e & 1) << 4 |
                            (f & 1) << 5 ;

    if (a)                               { }
    else if (b)                          { }
    else if (c)                          { }
    else if (!d)                         { }
    else if (e && !f)                    { }
    else if (a || b || c || d || e || f) { }
    else if (a && b && c && d && e && f) { }
    else if (a is b)                     { }
    else if (c is not d)                 { }
    else if (a == b)                     { }
    else if (c != d)                     { }
    else if (a and b)                    { }
    else if (c or d)                     { }
    else                                 { }

    switch (vector)
    {
        case 0x0:   break;
        case 0x1:   break;
        case 0x3:   break;
        case 0x7:   break;
        case 0xF:   break;
        case 0x1F:  break;
        case 0x3F:  break;
        case 0x7F:  break;
        case 0xFF:  break;
        default:    break;
    }
}
