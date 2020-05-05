# Notes

## Data Encoding/Decoding

Consider a command-handling system which supports a number encoded messages. In
this example, we support a number of message types:

packet type 1:
|------|------|------|-----|-------|-------|-------|-------|
| 0x01 | cnt1 | cnt0 | val | data3 | data2 | data1 | data0 |

packet type 2:
|------|------|------|-------|-------|-------|-------|-------|-------|-------|-------|
| 0x02 | cnt1 | cnt0 | dw1_3 | dw1_2 | dw1_1 | dw1_0 | dw2_3 | dw2_2 | dw2_1 | dw2_0 | 

One approach is to write functions to encode and decode each packet type.

```C
int pack_type1(uint8_t *buf, uint16_t count, uint8_t val, uint32_t data) {
  uint8_t *bp;

  bp = buf;
  *bp++ = 0x01;
  *bp++ = count >> 8;
  *bp++ = count;
  *bp++ = val;
  *bp++ = data >> 24;
  *bp++ = data >> 16;
  *bp++ = data >> 8;
  *bp++ = data;

  return bp - buf;
}
```



## Grep






## Virtual Machines