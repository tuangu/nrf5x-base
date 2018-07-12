/**
 * ZBOSS Zigbee 3.0
 * 
 * Copyright (c) 2012-2018 DSR Corporation, Denver CO, USA.
 * http://www.dsr-zboss.com
 * http://www.dsr-corporation.com
 * 
 * All rights reserved.
 * 
 * 
 * Use in source and binary forms, redistribution in binary form only, with
 * or without modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 * 
 * 2. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 * 
 * 3. This software, with or without modification, must only be used with a Nordic
 *    Semiconductor ASA integrated circuit.
 * 
 * 4. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 * 
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * PURPOSE: Level control cluster definitions
*/

#if !defined ZB_ZCL_LEVEL_CONTROL_H
#define ZB_ZCL_LEVEL_CONTROL_H

#include "zcl/zb_zcl_common.h"
#include "zcl/zb_zcl_commands.h"

/** @cond DOXYGEN_ZCL_SECTION */

/** @addtogroup ZB_ZCL_LEVEL_CONTROL
    @{
*/

/* ZB_ZCL_CLUSTER_ID_LEVEL_CONTROL = 0x0008 defined in zb_zcl_common.h */

/*! @name Level Control cluster attributes
    @{
*/

/** @brief Level Control cluster information attribute identifiers
    @see ZCL spec, subclause 3.10.2.2
*/

/**
 * @brief Level control attribute list
 */
enum zb_zcl_level_control_attr_e
{
  /*! @brief Current Level attribute */
  ZB_ZCL_ATTR_LEVEL_CONTROL_CURRENT_LEVEL_ID  = 0,
  /*! @brief Remaining Time attribute */
  ZB_ZCL_ATTR_LEVEL_CONTROL_REMAINING_TIME_ID  = 1,
  /*! @brief On Off Transition Time attribute */
  ZB_ZCL_ATTR_LEVEL_CONTROL_ON_OFF_TRANSITION_TIME_ID  = 0x10,
  /*! @brief On Level attribute */

  /* TODO: A close relationship between this cluster and the On/Off
   * cluster is needed. Refer to ZCL spec, subclause 3.10.2.1 */
  ZB_ZCL_ATTR_LEVEL_CONTROL_ON_LEVEL_ID = 0x11,
  /*! @internal Special Move Variables attribute */
  ZB_ZCL_ATTR_LEVEL_CONTROL_MOVE_STATUS_ID = 0xffff
};

/** @brief Current Level attribute minimum value */
#define ZB_ZCL_LEVEL_CONTROL_LEVEL_MIN_VALUE 0x00

/** @brief Current Level attribute maximum value */
#define ZB_ZCL_LEVEL_CONTROL_LEVEL_MAX_VALUE 0xff
/** @brief Current Level attribute maximum value */
#define ZB_ZCL_LEVEL_CONTROL_LEVEL_MAX_VALUE_SHADE 0xff

/** @brief Current Level attribute default value */
#define ZB_ZCL_LEVEL_CONTROL_CURRENT_LEVEL_DEFAULT_VALUE ZB_ZCL_LEVEL_CONTROL_LEVEL_MIN_VALUE

#define ZB_ZCL_LEVEL_CONTROL_REMAINING_TIME_DEFFAULT_VALUE_ZLL  0

/** @brief Transition Time as fast as able value
 see ZCL spec 3.10.2.3.1.2 */
#define ZB_ZCL_LEVEL_CONTROL_TRANSITION_TIME_AS_FAST_AS_ABLE 0xffff

//#define ZB_ZCL_LEVEL_CONTROL_TRANSITION_TIME_ERROR 20

#define ZB_ZCL_LEVEL_CONTROL_RATE_AS_FAST_AS_ABLE 0xff

/*! @} */ /* Level Control cluster attributes */

/*! @name Level Control cluster internals
    Internal structures for Level Control cluster
    @internal
    @{
*/

#define ZB_SET_ATTR_DESCR_WITH_ZB_ZCL_ATTR_LEVEL_CONTROL_CURRENT_LEVEL_ID(data_ptr)       \
{                                                                                         \
  ZB_ZCL_ATTR_LEVEL_CONTROL_CURRENT_LEVEL_ID,                                             \
  ZB_ZCL_ATTR_TYPE_U8,                                                                    \
  ZB_ZCL_ATTR_ACCESS_READ_ONLY | ZB_ZCL_ATTR_ACCESS_REPORTING | ZB_ZCL_ATTR_ACCESS_SCENE, \
  (zb_voidp_t) data_ptr                                                                   \
}

#define ZB_SET_ATTR_DESCR_WITH_ZB_ZCL_ATTR_LEVEL_CONTROL_REMAINING_TIME_ID(data_ptr)\
{                                                                                   \
  ZB_ZCL_ATTR_LEVEL_CONTROL_REMAINING_TIME_ID,                                      \
  ZB_ZCL_ATTR_TYPE_U16,                                                             \
  ZB_ZCL_ATTR_ACCESS_READ_ONLY,                                                     \
  (zb_voidp_t) data_ptr                                                             \
}

#define ZB_SET_ATTR_DESCR_WITH_ZB_ZCL_ATTR_LEVEL_CONTROL_MOVE_STATUS_ID(data_ptr) \
{                                                                                 \
  ZB_ZCL_ATTR_LEVEL_CONTROL_MOVE_STATUS_ID,                                       \
  ZB_ZCL_ATTR_TYPE_NULL,                                                          \
  ZB_ZCL_ATTR_ACCESS_READ_ONLY,                                                   \
  (zb_voidp_t) data_ptr                                                           \
}

/** @internal Structure of addr variables for Move commands
 */
typedef struct zb_zcl_level_control_move_addr_s
{
  zb_uint16_t src_addr;
  zb_uint8_t  src_endpoint;
  zb_uint8_t  dst_endpoint;
  zb_uint8_t  cmd_id;
  zb_uint8_t  seq_number;
  zb_bool_t disable_default_response;
  zb_uint16_t profile_id;
} zb_zcl_level_control_move_addr_t;

/** @internal Structure of Move variables for Move alarm
 */
typedef struct zb_zcl_level_control_move_variables_s
{
  /** @brief Level to set */
  zb_uint8_t curr_level;
  /** @brief End level */
  zb_uint8_t end_level;
  /** @brief On/Off flag: ZB_TRUE - need to setting On/Off attribute, ZB_FALSE - do not need */
  zb_bool_t is_onoff;
  /** @brief Address for response sending */
  zb_zcl_level_control_move_addr_t addr;
  /** brief Start time for set Remaining Time attribute */
  zb_uint16_t start_time;

//TODO: ifndef for debug only, need to remove
#ifdef OBSOLETE
  /* { OBSOLETE */
  /** @brief Time to next sheduled alarm */
  zb_uint16_t one_transition_time;
  /** @brief Move difference for one alarm */
  zb_uint8_t step;
  /** @brief Direction: ZB_TRUE - decrement level, ZB_FALSE - increment value */
  zb_bool_t direction_decrement;
  /** @brief Number of steps */
  zb_uint8_t step_number;
  /** @brief Step which from need to increment level (backward) */
  zb_uint8_t incr_level;
  /** @brief Step which from need to increment time (backward) */
  zb_uint8_t incr_time;
  /** @brief End time */
  zb_uint16_t end_time;
  /** @brief Allowable error (for time) in 1/10 of seconds */
  zb_uint16_t err;
  /** @brief Transition Time for all move */
  zb_uint16_t transition_time;
  /* OBSOLETE } */
#endif
} zb_zcl_level_control_move_variables_t;


typedef void (ZB_CODE * zb_zcl_level_control_handler_t)(zb_uint8_t ep, zb_uint8_t new_level);

/** @internal Structure of Move Status attribute for Move alarm
 */
typedef struct zb_zcl_level_control_move_status_s
{
//TODO: ifndef for debug only, need to remove
#ifdef OBSOLETE
  /** @brief Processing flag: ZB_TRUE - Move in progress, ZB_FALSE - not */
  zb_bool_t processing;
#endif
//TODO: level_control_handler needed for compilation only
  /** @brief Pointer to device handler */
  zb_zcl_level_control_handler_t level_control_handler;
  /** @brief Buffer id for Move Command */
  zb_uint8_t buf_id;
//TODO: scene flags?
//TODO: need to discuss
} ZB_PACKED_STRUCT zb_zcl_level_control_move_status_t;


/*!
  Declare attribute list for Level Control cluster
  @param attr_list - attribure list name
  @param current_level - pointer to variable to store current_level attribute value
  @param remaining_time - pointer to variable to store remaining_time attribute value
*/
#define ZB_ZCL_DECLARE_LEVEL_CONTROL_ATTRIB_LIST(attr_list, current_level, remaining_time)  \
  zb_zcl_level_control_move_status_t move_status_data_ctx## _attr_list;                     \
  ZB_ZCL_START_DECLARE_ATTRIB_LIST(attr_list)                                               \
  ZB_ZCL_SET_ATTR_DESC(ZB_ZCL_ATTR_LEVEL_CONTROL_CURRENT_LEVEL_ID, (current_level))         \
  ZB_ZCL_SET_ATTR_DESC(ZB_ZCL_ATTR_LEVEL_CONTROL_REMAINING_TIME_ID, (remaining_time))       \
  ZB_ZCL_SET_ATTR_DESC(ZB_ZCL_ATTR_LEVEL_CONTROL_MOVE_STATUS_ID,                            \
                       (&(move_status_data_ctx## _attr_list)))                              \
  ZB_ZCL_FINISH_DECLARE_ATTRIB_LIST

/*! Number of attributes mandatory for reporting in Level Control cluster */
#define ZB_ZCL_LEVEL_CONTROL_REPORT_ATTR_COUNT 1

/*! @} */ /* Level Control cluster internals */

/*! @name Level Control cluster commands
    @{
*/

/* Oct 16, 2012 CR:MINOR It would be better to group types and definitions related to a command (or
 * a request-response pair) with
 *    "/ ** @name <Readable command name> @{ * /
 *    <definitions
 *    / ** @} * /"
 * Doxygen tags.
 CR:FIXED*/

/*! @brief Level control cluster command identifiers
    @see ZCL spec, subclause 3.10.2.3
*/
enum zb_zcl_level_control_cmd_e
{
  /* Oct 16, 2012 CR:MEDIUM While enumeration literals have readable names, it would be better to
   * copy their names (and, possibly, some specific information on them) from corresponding spec
   * clauses.
   CR:FIXED*/
  /** Move To Level command */
  ZB_ZCL_CMD_LEVEL_CONTROL_MOVE_TO_LEVEL             = 0x00,
  /** Move command */
  ZB_ZCL_CMD_LEVEL_CONTROL_MOVE                      = 0x01,
  /** Step command */
  ZB_ZCL_CMD_LEVEL_CONTROL_STEP                      = 0x02,
  /** Stop command */
  ZB_ZCL_CMD_LEVEL_CONTROL_STOP                      = 0x03,
  /** Move To Level with On/Off command */
  ZB_ZCL_CMD_LEVEL_CONTROL_MOVE_TO_LEVEL_WITH_ON_OFF = 0x04,
  /** Move with On/Off command */
  ZB_ZCL_CMD_LEVEL_CONTROL_MOVE_WITH_ON_OFF          = 0x05,
  /** Step with On/Off command */
  ZB_ZCL_CMD_LEVEL_CONTROL_STEP_WITH_ON_OFF          = 0x06,
  /** Step with On/Off command */
  ZB_ZCL_CMD_LEVEL_CONTROL_STOP_WITH_ON_OFF          = 0x07
};

/************************** Level Control cluster command definitions ****************************/

/* command request structure */

/*! @brief Structured representsation of MOVE_TO_LEVEL command payload
    @see ZCL spec, subclause 3.10.2.3.1.1*/
typedef ZB_PACKED_PRE struct zb_zcl_level_control_move_to_level_req_s
{
  /** Level field */
  zb_uint8_t level;
  /** Transition time field */
  zb_uint16_t transition_time;
} ZB_PACKED_STRUCT zb_zcl_level_control_move_to_level_req_t;

/** @brief Move to Level payload length macro */
#define ZB_ZCL_LEVEL_CONTROL_MOVE_TO_LEVEL_REQ_PAYLOAD_LEN \
  sizeof(zb_zcl_level_control_move_to_level_req_t)

/** @internal Macro for sending Move to Level command */
#define ZB_ZCL_LEVEL_CONTROL_SEND_MOVE_TO_LEVEL_CMD(buffer, addr, dst_addr_mode,           \
  dst_ep, ep, prfl_id, def_resp, cb, level, transition_time, cmd_id)                       \
{                                                                                          \
  zb_uint8_t* ptr = ZB_ZCL_START_PACKET_REQ(buffer)                                           \
  ZB_ZCL_CONSTRUCT_SPECIFIC_COMMAND_REQ_FRAME_CONTROL(ptr, (def_resp))                    \
  ZB_ZCL_CONSTRUCT_COMMAND_HEADER_REQ(ptr, ZB_ZCL_GET_SEQ_NUM(), (cmd_id));                    \
  ZB_ZCL_PACKET_PUT_DATA8(ptr, (level));                                                   \
  ZB_ZCL_PACKET_PUT_DATA16_VAL(ptr, (transition_time));                                    \
  ZB_ZCL_FINISH_PACKET((buffer), ptr)                                                     \
  ZB_ZCL_SEND_COMMAND_SHORT(                                                               \
   buffer, addr, dst_addr_mode, dst_ep, ep, prfl_id, ZB_ZCL_CLUSTER_ID_LEVEL_CONTROL, cb); \
}

/** @internal Macro for getting Move to Level command */
#define ZB_ZCL_LEVEL_CONTROL_GET_MOVE_TO_LEVEL_CMD(data_buf, move_to_level_req, status)          \
{                                                                                                \
  zb_zcl_level_control_move_to_level_req_t *move_to_level_req_ptr;                               \
  (move_to_level_req_ptr) = ZB_BUF_LEN(data_buf) >=                                              \
    ZB_ZCL_LEVEL_CONTROL_MOVE_TO_LEVEL_REQ_PAYLOAD_LEN ?                                         \
    (zb_zcl_level_control_move_to_level_req_t*)ZB_BUF_BEGIN(data_buf) : NULL;                    \
  if (move_to_level_req_ptr)                                                                     \
  {                                                                                              \
    ZB_HTOLE16(&(move_to_level_req).transition_time, &(move_to_level_req_ptr->transition_time)); \
    move_to_level_req.level = move_to_level_req_ptr->level;                                      \
    status = ZB_TRUE;                                                                            \
  }                                                                                              \
  else                                                                                           \
  {                                                                                              \
    status = ZB_FALSE;                                                                           \
  }                                                                                              \
}

/* Oct 16, 2012 CR:MINOR Is there any notice on spec subclause defining the command?
   CR: No, there is only Payload format and Effect on receipt */


/*! @brief Send Move to Level command
    @param buffer - to put packet to
    @param addr - address to send packet to
    @param dst_addr_mode - addressing mode
    @param dst_ep - destination endpoint
    @param ep - sending endpoint
    @param prfl_id - profile identifier
    @param def_resp - enable/disable default response
    @param cb - callback for getting command send status
    @param level - Level value
    @param transition_time - Transition Time value
*/

#define ZB_ZCL_LEVEL_CONTROL_SEND_MOVE_TO_LEVEL_REQ(buffer, addr, dst_addr_mode,      \
  dst_ep, ep, prfl_id, def_resp, cb, level, transition_time)                          \
{                                                                                     \
  ZB_ZCL_LEVEL_CONTROL_SEND_MOVE_TO_LEVEL_CMD(buffer,                                 \
                                              addr,                                   \
                                              dst_addr_mode,                          \
                                              dst_ep,                                 \
                                              ep,                                     \
                                              prfl_id,                                \
                                              def_resp,                               \
                                              cb,                                     \
                                              level,                                  \
                                              transition_time,                        \
                                              ZB_ZCL_CMD_LEVEL_CONTROL_MOVE_TO_LEVEL) \
}

/*!
  @brief Parses Get Move to Level command and fills data request structure.
  @param data_buf - pointer to zb_buf_t buffer containing command request data
  @param move_to_level_req - variable to save command request
  @param status - succsess or not read parameters - ZB_TRUE or ZB_FALSE
  @note data_buf buffer should contain command request payload without ZCL header.
*/

#define ZB_ZCL_LEVEL_CONTROL_GET_MOVE_TO_LEVEL_REQ(data_buf, move_to_level_req, status) \
{                                                                                       \
  ZB_ZCL_LEVEL_CONTROL_GET_MOVE_TO_LEVEL_CMD(data_buf, move_to_level_req, status);      \
}

/*! @brief Send Move to Level with On/Off command
    @param buffer - to put packet to
    @param addr - address to send packet to
    @param dst_addr_mode - addressing mode
    @param dst_ep - destination endpoint
    @param ep - sending endpoint
    @param prfl_id - profile identifier
    @param def_resp - enable/disable default response
    @param cb - callback for getting command send status
    @param level - Level value
    @param transition_time - Transition Time value
*/

#define ZB_ZCL_LEVEL_CONTROL_SEND_MOVE_TO_LEVEL_WITH_ON_OFF_REQ(buffer, addr, dst_addr_mode,      \
  dst_ep, ep, prfl_id, def_resp, cb, level, transition_time)                                      \
{                                                                                                 \
  ZB_ZCL_LEVEL_CONTROL_SEND_MOVE_TO_LEVEL_CMD(buffer,                                             \
                                              addr,                                               \
                                              dst_addr_mode,                                      \
                                              dst_ep,                                             \
                                              ep,                                                 \
                                              prfl_id,                                            \
                                              def_resp,                                           \
                                              cb,                                                 \
                                              level,                                              \
                                              transition_time,                                    \
                                              ZB_ZCL_CMD_LEVEL_CONTROL_MOVE_TO_LEVEL_WITH_ON_OFF) \
}

/*!
  @brief Parses Get Move to Level with On/Off command and fills data request
  structure.
  @param data_buf - pointer to zb_buf_t buffer containing command request data
  @param move_to_level_req - variable to save command request.
  @param status - succsess or not read parameters - ZB_TRUE or ZB_FALSE
  @note data_buf buffer should contain command request payload without ZCL header.
*/

#define ZB_ZCL_LEVEL_CONTROL_GET_MOVE_TO_LEVEL_WITH_ON_OFF_REQ(                   \
  data_buf, move_to_level_req, status)                                            \
{                                                                                 \
  ZB_ZCL_LEVEL_CONTROL_GET_MOVE_TO_LEVEL_CMD(data_buf, move_to_level_req, status); \
}


enum zb_zcl_level_control_move_mode_e
{
  ZB_ZCL_LEVEL_CONTROL_MOVE_MODE_UP   = 0x00,
  ZB_ZCL_LEVEL_CONTROL_MOVE_MODE_DOWN = 0x01
};

/*! @brief Structured representsation of MOVE command payload */
typedef ZB_PACKED_PRE struct zb_zcl_level_control_move_req_s
{
  /** Move Mode field */
  zb_uint8_t move_mode;
  /** Rate field */
  zb_uint8_t rate;
} ZB_PACKED_STRUCT zb_zcl_level_control_move_req_t;

/** @brief Move payload length macro */
#define ZB_ZCL_LEVEL_CONTROL_MOVE_REQ_PAYLOAD_LEN \
  sizeof(zb_zcl_level_control_move_req_t)

/** @internal Macro for sending Move command */
#define ZB_ZCL_LEVEL_CONTROL_SEND_MOVE_CMD(                                                 \
  buffer, addr, dst_addr_mode, dst_ep, ep, prfl_id, def_resp, cb, move_mode, rate, cmd_id)  \
{                                                                                           \
  zb_uint8_t* ptr = ZB_ZCL_START_PACKET_REQ(buffer)                                            \
  ZB_ZCL_CONSTRUCT_SPECIFIC_COMMAND_REQ_FRAME_CONTROL(ptr, def_resp)                       \
  ZB_ZCL_CONSTRUCT_COMMAND_HEADER_REQ(ptr, ZB_ZCL_GET_SEQ_NUM(), cmd_id);                       \
  ZB_ZCL_PACKET_PUT_DATA8(ptr, (move_mode));                                                \
  ZB_ZCL_PACKET_PUT_DATA8(ptr, (rate));                                                     \
  ZB_ZCL_FINISH_PACKET(buffer, ptr)                                                        \
  ZB_ZCL_SEND_COMMAND_SHORT(                                                                \
    buffer, addr, dst_addr_mode, dst_ep, ep, prfl_id, ZB_ZCL_CLUSTER_ID_LEVEL_CONTROL, cb); \
}

/** @internal Macro for getting Move command */
#define ZB_ZCL_LEVEL_CONTROL_GET_MOVE_CMD(data_buf, move_req, status)                  \
{                                                                                      \
  zb_zcl_level_control_move_req_t *move_req_ptr;                                       \
  (move_req_ptr) = ZB_BUF_LEN(data_buf) >= ZB_ZCL_LEVEL_CONTROL_MOVE_REQ_PAYLOAD_LEN ? \
    (zb_zcl_level_control_move_req_t*)ZB_BUF_BEGIN(data_buf) : NULL;                   \
  if (move_req_ptr)                                                                    \
  {                                                                                    \
    ZB_MEMCPY(&(move_req), move_req_ptr, sizeof(zb_zcl_level_control_move_req_t));     \
    status = ZB_TRUE;                                                                  \
  }                                                                                    \
  else                                                                                 \
  {                                                                                    \
    status = ZB_FALSE;                                                                 \
  }                                                                                    \
}

/*! @brief Send Move command
    @param buffer - to put packet to
    @param addr - address to send packet to
    @param dst_addr_mode - addressing mode
    @param dst_ep - destination endpoint
    @param ep - sending endpoint
    @param prfl_id - profile identifier
    @param def_resp - enable/disable default response
    @param cb - callback for getting command send status
    @param move_mode - Move Mode value
    @param rate - Rate value
*/
#define ZB_ZCL_LEVEL_CONTROL_SEND_MOVE_REQ(buffer, addr, dst_addr_mode, \
  dst_ep, ep, prfl_id, def_resp, cb, move_mode, rate)                   \
{                                                                       \
  ZB_ZCL_LEVEL_CONTROL_SEND_MOVE_CMD(buffer,                            \
                                     addr,                              \
                                     dst_addr_mode,                     \
                                     dst_ep,                            \
                                     ep,                                \
                                     prfl_id,                           \
                                     def_resp,                          \
                                     cb,                                \
                                     move_mode,                         \
                                     rate,                              \
                                     ZB_ZCL_CMD_LEVEL_CONTROL_MOVE);    \
}

/*!
  @brief Parses Get Move command and fills data request
  structure.
  @param data_buf - pointer to zb_buf_t buffer containing command request data
  @param move_req - variable to save command request
  @param status - succsess or not read parameters - ZB_TRUE or ZB_FALSE
  @note data_buf buffer should contain command request payload without ZCL header.
*/

#define ZB_ZCL_LEVEL_CONTROL_GET_MOVE_REQ(data_buf, move_req, status)   \
{                                                                       \
  ZB_ZCL_LEVEL_CONTROL_GET_MOVE_CMD(data_buf, move_req, status);        \
}

/*! @brief Send Move with On/Off command
    @param buffer - to put packet to
    @param addr - address to send packet to
    @param dst_addr_mode - addressing mode
    @param dst_ep - destination endpoint
    @param ep - sending endpoint
    @param prfl_id - profile identifier
    @param def_resp - enable/disable default response
    @param cb - callback for getting command send status
    @param move_mode - Move Mode value
    @param rate - Rate value
*/

#define ZB_ZCL_LEVEL_CONTROL_SEND_MOVE_WITH_ON_OFF_REQ(                            \
  buffer, addr, dst_addr_mode, dst_ep, ep, prfl_id, def_resp, cb, move_mode, rate) \
{                                                                                  \
  ZB_ZCL_LEVEL_CONTROL_SEND_MOVE_CMD(buffer,                                       \
                                     addr,                                         \
                                     dst_addr_mode,                                \
                                     dst_ep,                                       \
                                     ep,                                           \
                                     prfl_id,                                      \
                                     def_resp,                                     \
                                     cb,                                           \
                                     move_mode,                                    \
                                     rate,                                         \
                                     ZB_ZCL_CMD_LEVEL_CONTROL_MOVE_WITH_ON_OFF);   \
}

/*!
  @brief Parses Get Move with On/Off command and fills data request
  structure.
  @param data_buf - pointer to zb_buf_t buffer containing command request data
  @param move_req - variable to save command request
  @param status - succsess or not read parameters - ZB_TRUE or ZB_FALSE
  @note data_buf buffer should contain command request payload without ZCL header.
*/

#define ZB_ZCL_LEVEL_CONTROL_GET_MOVE_WITH_ON_OFF_REQ(data_buf, move_req, status) \
{                                                                                 \
  ZB_ZCL_LEVEL_CONTROL_GET_MOVE_CMD(data_buf, move_req, status);                  \
}

enum zb_zcl_level_control_step_mode_e
{
  ZB_ZCL_LEVEL_CONTROL_STEP_MODE_UP   = 0x00,
  ZB_ZCL_LEVEL_CONTROL_STEP_MODE_DOWN = 0x01
};

/*! @brief Structured representsation of STEP command payload */
typedef ZB_PACKED_PRE struct zb_zcl_level_control_step_req_s
{
  /** Step Mode field */
  zb_uint8_t step_mode;
  /** Step Size field */
  zb_uint8_t step_size;
  /** Transition Time field */
  zb_uint16_t transition_time;
} ZB_PACKED_STRUCT zb_zcl_level_control_step_req_t;

/** @brief Step payload length macro */
#define ZB_ZCL_LEVEL_CONTROL_STEP_REQ_PAYLOAD_LEN \
  sizeof(zb_zcl_level_control_step_req_t)


/** @internal Macro for sending Step command */
#define ZB_ZCL_LEVEL_CONTROL_SEND_STEP_CMD(buffer,                      \
                                           addr,                        \
                                           dst_addr_mode,               \
                                           dst_ep,                      \
                                           ep,                          \
                                           prfl_id,                     \
                                           def_resp,                    \
                                           cb,                          \
                                           step_mode,                   \
                                           step_size,                   \
                                           transition_time,             \
                                           cmd_id)                      \
{                                                                       \
  zb_uint8_t* ptr = ZB_ZCL_START_PACKET_REQ(buffer)                        \
  ZB_ZCL_CONSTRUCT_SPECIFIC_COMMAND_REQ_FRAME_CONTROL(ptr, def_resp)   \
  ZB_ZCL_CONSTRUCT_COMMAND_HEADER_REQ(ptr, ZB_ZCL_GET_SEQ_NUM(), cmd_id);   \
  ZB_ZCL_PACKET_PUT_DATA8(ptr, (step_mode));                            \
  ZB_ZCL_PACKET_PUT_DATA8(ptr, (step_size));                            \
  ZB_ZCL_PACKET_PUT_DATA16_VAL(ptr, (transition_time));                 \
  ZB_ZCL_FINISH_PACKET(buffer, ptr)                                    \
  ZB_ZCL_SEND_COMMAND_SHORT(buffer,                                     \
                            addr,                                       \
                            dst_addr_mode,                              \
                            dst_ep,                                     \
                            ep,                                         \
                            prfl_id,                                    \
                            ZB_ZCL_CLUSTER_ID_LEVEL_CONTROL,            \
                            cb);                                        \
}


/** @internal Macro for getting Step command */
#define ZB_ZCL_LEVEL_CONTROL_GET_STEP_CMD(data_buf, step_req, status)                  \
{                                                                                      \
  zb_zcl_level_control_step_req_t *step_req_ptr;                                       \
  (step_req_ptr) = ZB_BUF_LEN(data_buf) == ZB_ZCL_LEVEL_CONTROL_STEP_REQ_PAYLOAD_LEN ? \
    (zb_zcl_level_control_step_req_t*)ZB_BUF_BEGIN(data_buf) : NULL;                   \
  if (step_req_ptr)                                                                    \
  {                                                                                    \
    step_req.step_mode = step_req_ptr->step_mode;                                      \
    step_req.step_size = step_req_ptr->step_size;                                      \
    ZB_HTOLE16(&(step_req).transition_time, &step_req_ptr->transition_time);           \
    status = ZB_TRUE;                                                                  \
  }                                                                                    \
  else                                                                                 \
  {                                                                                    \
    status = ZB_FALSE;                                                                 \
  }                                                                                    \
}

/*! @brief Send Step command
    @param buffer - to put packet to
    @param addr - address to send packet to
    @param dst_addr_mode - addressing mode
    @param dst_ep - destination endpoint
    @param ep - sending endpoint
    @param prfl_id - profile identifier
    @param def_resp - enable/disable default response
    @param cb - callback for getting command send status
    @param step_mode - Step Mode value
    @param step_size - Step Size value
    @param transition_time - Transition Time value
*/

#define ZB_ZCL_LEVEL_CONTROL_SEND_STEP_REQ(buffer,                   \
                                           addr,                     \
                                           dst_addr_mode,            \
                                           dst_ep,                   \
                                           ep,                       \
                                           prfl_id,                  \
                                           def_resp,                 \
                                           cb,                       \
                                           step_mode,                \
                                           step_size,                \
                                           transition_time)          \
{                                                                    \
  ZB_ZCL_LEVEL_CONTROL_SEND_STEP_CMD(buffer,                         \
                                     addr,                           \
                                     dst_addr_mode,                  \
                                     dst_ep,                         \
                                     ep,                             \
                                     prfl_id,                        \
                                     def_resp,                       \
                                     cb,                             \
                                     step_mode,                      \
                                     step_size,                      \
                                     transition_time,                \
                                     ZB_ZCL_CMD_LEVEL_CONTROL_STEP); \
}

/*!
  @brief Parses Get Step command and fills data request
  structure.
  @param data_buf - pointer to zb_buf_t buffer containing command request data
  @param step_req - variable to save command request
  @param status - succsess or not read parameters - ZB_TRUE or ZB_FALSE
  @note data_buf buffer should contain command request payload without ZCL header.
*/

#define ZB_ZCL_LEVEL_CONTROL_GET_STEP_REQ(data_buf, step_req, status)   \
{                                                                       \
  ZB_ZCL_LEVEL_CONTROL_GET_STEP_CMD(data_buf, step_req, status);        \
}

/*! @brief Send Step with On/Off command
  @param buffer - to put packet to
    @param addr - address to send packet to
    @param dst_addr_mode - addressing mode
    @param dst_ep - destination endpoint
    @param ep - sending endpoint
    @param prfl_id - profile identifier
    @param def_resp - enable/disable default response
    @param cb - callback for getting command send status
    @param step_mode - Step Mode value
    @param step_size - Step Size value
    @param transition_time - Transition Time value
*/

#define ZB_ZCL_LEVEL_CONTROL_SEND_STEP_WITH_ON_OFF_REQ(buffer,                   \
                                                       addr,                     \
                                                       dst_addr_mode,            \
                                                       dst_ep,                   \
                                                       ep,                       \
                                                       prfl_id,                  \
                                                       def_resp,                 \
                                                       cb,                       \
                                                       step_mode,                \
                                                       step_size,                \
                                                       transition_time)          \
{                                                                                \
  ZB_ZCL_LEVEL_CONTROL_SEND_STEP_CMD(buffer,                                     \
                                     addr,                                       \
                                     dst_addr_mode,                              \
                                     dst_ep,                                     \
                                     ep,                                         \
                                     prfl_id,                                    \
                                     def_resp,                                   \
                                     cb,                                         \
                                     step_mode,                                  \
                                     step_size,                                  \
                                     transition_time,                            \
                                     ZB_ZCL_CMD_LEVEL_CONTROL_STEP_WITH_ON_OFF); \
}

/*!
  @brief Parses Get Step with On/Off command and fills data request
  structure.
  @param data_buf - pointer to zb_buf_t buffer containing command request data
  @param step_req - variable to save command request
  @param status - succsess or not read parameters - ZB_TRUE or ZB_FALSE
  @note data_buf buffer should contain command request payload without ZCL header.
*/

#define ZB_ZCL_LEVEL_CONTROL_GET_STEP_WITH_ON_OFF_REQ(data_buf, step_req, status) \
  {                                                                               \
  ZB_ZCL_LEVEL_CONTROL_GET_STEP_CMD(data_buf, step_req, status);                  \
}

/*! @brief Send Stop command
    @param buffer - to put packet to
    @param addr - address to send packet to
    @param dst_addr_mode - addressing mode
    @param dst_ep - destination endpoint
    @param ep - sending endpoint
    @param prfl_id - profile identifier
    @param def_resp - enable/disable default response
    @param cb - callback for getting command send status
*/

#define ZB_ZCL_LEVEL_CONTROL_SEND_STOP_REQ(                                                  \
  buffer, addr, dst_addr_mode, dst_ep, ep, prfl_id, def_resp, cb)                            \
{                                                                                            \
  zb_uint8_t* ptr = ZB_ZCL_START_PACKET_REQ(buffer)                                             \
  ZB_ZCL_CONSTRUCT_SPECIFIC_COMMAND_REQ_FRAME_CONTROL(ptr, def_resp)                        \
  ZB_ZCL_CONSTRUCT_COMMAND_HEADER_REQ(ptr, ZB_ZCL_GET_SEQ_NUM(), ZB_ZCL_CMD_LEVEL_CONTROL_STOP); \
  ZB_ZCL_FINISH_PACKET(buffer, ptr)                                                         \
  ZB_ZCL_SEND_COMMAND_SHORT(                                                                 \
    buffer, addr, dst_addr_mode, dst_ep, ep, prfl_id, ZB_ZCL_CLUSTER_ID_LEVEL_CONTROL, cb);  \
}

/*! @brief Send Stop with On/off command
    @param buffer - to put packet to
    @param addr - address to send packet to
    @param dst_addr_mode - addressing mode
    @param dst_ep - destination endpoint
    @param ep - sending endpoint
    @param prfl_id - profile identifier
    @param def_resp - enable/disable default response
    @param cb - callback for getting command send status
*/

#define ZB_ZCL_LEVEL_CONTROL_SEND_STOP_WITH_ON_OFF_REQ(                                      \
  buffer, addr, dst_addr_mode, dst_ep, ep, prfl_id, def_resp, cb)                            \
  ZB_ZCL_LEVEL_CONTROL_SEND_STOP_REQ(buffer, addr, dst_addr_mode, dst_ep, ep, prfl_id, def_resp, cb)

/*! @internal Setting current level value macro:
    @param ep - endpoint where setting
    @param value - new level value
*/
#define ZB_ZCL_LEVEL_CONTROL_SET_LEVEL_VALUE(ep, value)            \
{                                                                  \
  zb_uint8_t val = (value);                                        \
  ZB_ZCL_SET_ATTRIBUTE((ep),                                       \
                       ZB_ZCL_CLUSTER_ID_LEVEL_CONTROL,            \
                       ZB_ZCL_CLUSTER_SERVER_ROLE,                 \
                       ZB_ZCL_ATTR_LEVEL_CONTROL_CURRENT_LEVEL_ID, \
                       &val,                                       \
                       ZB_FALSE);                                  \
}

/*! @internal Setting On/Off value macro:
    @param ep - endpoint where setting
    @param on_off_value - on/off value
*/
#define ZB_ZCL_LEVEL_CONTROL_SET_ON_OFF_VALUE(ep, on_off_value)    \
{                                                                  \
  zb_uint8_t val = (on_off_value);                                 \
  ZB_ZCL_SET_ATTRIBUTE((ep),                                       \
                       ZB_ZCL_CLUSTER_ID_ON_OFF,                   \
                       ZB_ZCL_CLUSTER_SERVER_ROLE,                 \
                       ZB_ZCL_ATTR_ON_OFF_ON_OFF_ID,               \
                       &val,                                       \
                       ZB_FALSE);                                  \
}

//ZB_ZCL_LEVEL_CONTROL_SET_HANDLER is obsolete
/*! @internal Setting device handler macro:
    @param ep - endpoint where setting
    @param handler - pointer to device handler
*/
#define ZB_ZCL_LEVEL_CONTROL_SET_HANDLER(ep, handler)                            \
{                                                                                \
  zb_zcl_attr_t* move_status_desc;                                               \
  zb_zcl_level_control_move_status_t* move_status;                               \
                                                                                 \
  move_status_desc = zb_zcl_get_attr_desc_a((ep),                                \
    ZB_ZCL_CLUSTER_ID_LEVEL_CONTROL,                                             \
    ZB_ZCL_ATTR_LEVEL_CONTROL_MOVE_STATUS_ID);                                   \
  ZB_ASSERT(move_status_desc != NULL);                                           \
  move_status = (zb_zcl_level_control_move_status_t*)move_status_desc->data_p;   \
  move_status->level_control_handler = (handler);                                \
}

typedef struct zb_zcl_level_control_set_value_param_s
{
  zb_uint8_t new_value;
} zb_zcl_level_control_set_value_param_t;

  /* definition to parse request */

  /* command response structure */

  /* definition to parse response */

  /* definition to send command request */

/*! @} */ /* Level Control cluster commands */

/*! @} */ /* ZCL Level Control cluster definitions */

/** @endcond */

zb_void_t zb_zcl_level_control_init_server();
zb_void_t zb_zcl_level_control_init_client();
#define ZB_ZCL_CLUSTER_ID_LEVEL_CONTROL_SERVER_ROLE_INIT zb_zcl_level_control_init_server
#define ZB_ZCL_CLUSTER_ID_LEVEL_CONTROL_CLIENT_ROLE_INIT zb_zcl_level_control_init_client

#endif /* ZB_ZCL_LEVEL_CONTROL_H */