#ifndef __ASYNCBLINK_H
#define __ASYNCBLINK_H

#include <Arduino.h>

namespace ckxng {
  namespace asyncBlink {
    namespace _impl {
  
      /***
       *** STRUCTURE DEFINITIONS
       ***/
    
      /**
       * struct pinList
       *   A data structure for holding a sequence of pins and their states.  This
       *   allows blink to track the states of multiple pins simultaneously.
       * 
       * Data:
       * - int pin - the pin number on the board.  This pin should already
       *   be set to OUTPUT mode.
       * - int currentState - will begin as LOW, then toggle between LOW and 
       *   HIGH when blink(pin,ms) is called after ms milliseconds
       * - long lastChangeTimestamp - the timestamp in milliseconds of the 
       *   last time blink(pin,ms) changed the state of the LED
       * - pinList *next - a pointer to the next pin, or NULL
       */
      struct pinList {
        int pin = 0;
        int currentState = 0;
        long lastChangeTimestamp = 0;
        pinList *next = NULL;
      };
      
      /***
       *** GLOBAL VARIABLES
       ***/
      
      /**
       * pinList *pinData
       *   A GLOBAL VARIABLE that holds the pin data for blink
       */
      pinList *pinData = new pinList();
      
      /***
       *** FUNCTION DECLARATIONS
       ***/
      
      /**
       * void blink(int pin, int ms)
       *   Will cause a LED on pin to change state HIGH->LOW or LOW->HIGH if the
       *   state was last changed at least ms milliseconds ago.
       * 
       * Params:
       * - int pin - the pin number on the board.  This pin should already
       *   be set to OUTPUT mode.
       * - int ms - the number of milliseconds that must have passed before
       *   changing the state
       */
      void blink(int pin, int ms);
      
      /**
       * void blink(int pin, int ms, pinList *node)
       *   Will cause a LED on pin to change state HIGH->LOW or LOW->HIGH if the
       *   state was last changed at least ms milliseconds ago.  This function
       *   is called by blink(pin,ms) and is typically not called directly.
       * 
       * Params:
       * - int pin - the pin number on the board.  This pin should already
       *   be set to OUTPUT mode.
       * - int ms - the number of milliseconds that must have passed before
       *   changing the state
       * - pinList *node - the linked list that holds pin data
       */
      void _blink_r(int pin, int ms, pinList *node);
    }
    using _impl::blink;
  }
}

#endif
