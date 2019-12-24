#include "asyncBlink.h"

namespace ckxng {
  namespace asyncBlink {
    namespace _impl {

      void blink(int pin, int ms) {
        _blink_r(pin, ms, pinData);
      }
      
      void _blink_r(int pin, int ms, pinList *node) {
        /* something's wrong, abort! */
        if(node == NULL) {
          return;
          
        /* we found the right node for this pin */
        } else if(node->pin == pin) {
          long now = millis();
          
          /* flip the pin and set the timestamp if sufficient time has passed */
          if(node->lastChangeTimestamp + ms < now) {
            node->lastChangeTimestamp = now;
            node->currentState = node->currentState==HIGH?LOW:HIGH;
            digitalWrite(pin, node->currentState);
          }
          
        /* end of the list, append the pin to the list and recurse to it */
        } else if(node->next == NULL) {
          node->next = new pinList();
          node->next->pin = pin;
          node->next->currentState = LOW;
          _blink_r(pin, ms, node->next);
          
        /* search for the correct pin by recursing to the next node */
        } else {
          _blink_r(pin, ms, node->next);
        }
      }
    }
  }
}
