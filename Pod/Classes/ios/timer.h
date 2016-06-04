//
//  timer.h
//  Pods
//
//  Created by JIRENTIANXIANG on 5/10/16.
//
//

#ifndef timer_h
#define timer_h

dispatch_source_t CreateDispatchTimer(uint64_t interval,
                                      uint64_t leeway,
                                      dispatch_queue_t queue,
                                      dispatch_block_t block)
{
    dispatch_source_t timer = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER,
                                                     0, 0, queue);
    if (timer)
    {
        dispatch_source_set_timer(timer, dispatch_time(0, 0), interval, leeway);
        dispatch_source_set_event_handler(timer, block);
    }
    return timer;
}

#endif /* timer_h */
