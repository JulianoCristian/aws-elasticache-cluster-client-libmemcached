/*  vim:expandtab:shiftwidth=2:tabstop=2:smarttab:
 * 
 *  Libmemcached library
 *
 *  Copyright (C) 2011 Data Differential, http://datadifferential.com/
 *  Copyright (C) 2006-2009 Brian Aker All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *
 *      * Redistributions of source code must retain the above copyright
 *  notice, this list of conditions and the following disclaimer.
 *
 *      * Redistributions in binary form must reproduce the above
 *  copyright notice, this list of conditions and the following disclaimer
 *  in the documentation and/or other materials provided with the
 *  distribution.
 *
 *      * The names of its contributors may not be used to endorse or
 *  promote products derived from this software without specific prior
 *  written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *
 * Portions Copyright 2012-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You may not use this file except in
 * compliance with the License. A copy of the License is located at
 *
 *    http://aws.amazon.com/apache2.0/
 *
 * or in the "license" file accompanying this file. This file is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations under the License.
 */

#pragma once


#ifdef __cplusplus
extern "C" {
#endif

/* Server List Public functions */
LIBMEMCACHED_API
  void memcached_server_list_free(memcached_server_list_st ptr);

LIBMEMCACHED_API
  void reresolve_servers_in_client(memcached_instance_st **server_list, uint32_t server_count);

LIBMEMCACHED_API
  memcached_return_t memcached_server_push(memcached_st *ptr, const memcached_server_list_st list);

LIBMEMCACHED_API
  memcached_server_list_st memcached_server_list_append(memcached_server_list_st ptr,
                                                        const char *hostname,
                                                        in_port_t port,
                                                        memcached_return_t *error);

LIBMEMCACHED_API
memcached_return_t notify_server_list_update(memcached_st *ptr, memcached_server_list_st new_server_list);

LIBMEMCACHED_API
  memcached_server_st *parse_memcached_configuration(char *config);

LIBMEMCACHED_API
  memcached_server_list_st memcached_server_list_append_with_weight(memcached_server_list_st ptr,
                                                                    const char *hostname,
                                                                    in_port_t port,
                                                                    uint32_t weight,
                                                                    memcached_return_t *error);

LIBMEMCACHED_API
  memcached_server_list_st memcached_server_list_append_with_ipaddress(memcached_server_list_st ptr,
                                                                    const char *hostname,
                                                                    const char *ipaddress,
                                                                    in_port_t port,
                                                                    memcached_return_t *error);

LIBMEMCACHED_API
  uint32_t memcached_server_list_count(const memcached_server_list_st ptr);

#ifdef __cplusplus
} // extern "C"
#endif
