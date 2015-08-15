/*
 * Copyright © 2015 Red Hat, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef LIBRATBAG_HIDRAW_H
#define LIBRATBAG_HIDRAW_H

#include <linux/hid.h>

#include "libratbag.h"

/* defined in the internal hid API in the kernel */
#define HID_INPUT_REPORT	0
#define HID_OUTPUT_REPORT	1
#define HID_FEATURE_REPORT	2

int ratbag_open_hidraw(struct ratbag *ratbag);

/**
 * ratbag_hidraw_raw_request - send report request to device
 *
 * @ratbag: ratbag device
 * @reportnum: report ID
 * @buf: in/out data to transfer
 * @len: length of buf
 * @rtype: HID report type
 * @reqtype: HID_REQ_GET_REPORT or HID_REQ_SET_REPORT
 *
 * @return: count of data transfered, negative if error
 *
 * Same behavior as hid_hw_request, but with raw buffers instead.
 */
int ratbag_hidraw_raw_request(struct ratbag *ratbag, unsigned char reportnum,
		__u8 *buf, size_t len, unsigned char rtype, int reqtype);

/**
 * ratbag_hidraw_output_report - send output report to device
 *
 * @hdev: hid device
 * @buf: raw data to transfer
 * @len: length of buf
 *
 * @return: count of data transfered, negative if error
 */
int ratbag_hidraw_output_report(struct ratbag *ratbag, __u8 *buf, size_t len);

#endif /* LIBRATBAG_HIDRAW_H */
