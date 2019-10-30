/*
 * json_parse.c
 *
 *  Created on: Oct 12, 2019
 *      Author: mmcgr
 */
#include "json_parse.h"

int8_t LUT_array[256]={0};
jsmntok_t t[512];

void json_parse_topic_functions_init(topic_func_type *tfuncs)
{/*
    tfuncs[0] = &json_parse_topic0;
    tfuncs[1] = &json_parse_topic1;
    tfuncs[2] = &json_parse_topic2;
    tfuncs[3] = &json_parse_topic3;*/
}
void json_parse_big(const char *payload_p, uint16_t *msgID_p)
{
    //From jasmine example
    int r, i;
    uint16_t found = 0;
    jsmn_parser p;

    jsmn_init(&p);
    r = jsmn_parse(&p, payload_p, strlen(payload_p), t,
                   sizeof(t) / sizeof(t[0]));
    if (r < 0)
    {
        //Parser failed
        return;
    }
    if (r < 1 || t[0].type != JSMN_OBJECT)
    {
        //Unexpected Type
        return;
    }
    for (i = 1; i < r; i++)
    {
        if (!(strncmp(payload_p + t[i].start, JSON_parse_msgID, strlen(JSON_parse_msgID))))
        {
            *msgID_p = (uint16_t) strtoul(payload_p + t[i + 1].start, NULL, 0);
        }
        if(!(strncmp(payload_p+t[i].start, JSON_parse_LUT, strlen(JSON_parse_LUT))))
        {
            found = 1;
            if(t[i+1].type!=JSMN_ARRAY){
                continue;
            }
            if(t[i+1].size<PUBLISH_PAYLOAD_BUFFER_SIZE){

                int j;
                int test = sizeof(t) / sizeof(t[0]);
                for(j=0;j<t[i+1].size;j++)
                {
                    LUT_array[j]= (uint16_t) strtoul(payload_p + t[i+j+2].start, NULL, 0);
                }

                for(;j<LUT_SIZE;j++){
                    LUT_array[j]=0;
                }

            }

            i+=t[i+1].size+1;

        }
    }
    if (found)
    {
        sendTableMsgToMTQ_BL(1);
    }
}

void json_parse_topic1(const char *payload_p, uint16_t *msgID_p)
{
    //From jasmine example
    int r, i;
    uint16_t testVal = 0, found = 0;
    jsmn_parser p;

    jsmn_init(&p);
    r = jsmn_parse(&p, payload_p, strlen(payload_p), t,
                   sizeof(t) / sizeof(t[0]));
    if (r < 0)
    {
        //Parser failed
        return;
    }
    if (r < 1 || t[0].type != JSMN_OBJECT)
    {
        //Unexpected Type
        return;
    }
    for (i = 1; i < r; i++)
    {
        if (!(strncmp(payload_p + t[i].start, JSON_parse_msgID, strlen(JSON_parse_msgID))))
        {
            *msgID_p = (uint16_t) strtoul(payload_p + t[i + 1].start, NULL, 0);
        }
        if(!(strncmp(payload_p+t[i].start, JSON_parse_count, strlen(JSON_parse_count))))
        {
            found = 1;
            testVal = (uint16_t) strtoul(payload_p + t[i+1].start, NULL, 0);
        }
    }
    if (found)
    {
        sendTestMsgToMTQ_BL(testVal);
    }
}

void json_parse_topic2(const char *payload_p)
{

}

void json_parse_topic3(const char *payload_p)
{

}
void json_parse_recvd(const char *payload_p)
{


}

void json_stringify_topic0(char *payload_p, uint16_t msgID, uint16_t published_num, uint16_t received_num, uint16_t missed_num){
    char intBuffer[INT_BUFFER_SIZE];

    strcat(payload_p, JSON_INITIAL_KEY);

    strcat(payload_p, JSON_MSGID_KEY);
    sprintf(intBuffer,"%d", msgID);
    strcat(payload_p, intBuffer);

    strcat(payload_p, JSON_SEPERATOR_KEY);

    strcat(payload_p, JSON_NUMP_KEY);
    sprintf(intBuffer,"%d", published_num);
    strcat(payload_p, intBuffer);

    strcat(payload_p, JSON_SEPERATOR_KEY);

    strcat(payload_p, JSON_NUMR_KEY);
    sprintf(intBuffer,"%d", received_num);
    strcat(payload_p, intBuffer);

    strcat(payload_p, JSON_SEPERATOR_KEY);

    strcat(payload_p, JSON_NUMM_KEY);
    sprintf(intBuffer,"%d", missed_num);
    strcat(payload_p, intBuffer);

    strcat(payload_p, JSON_FINAL_KEY);
}

void json_stringify_topic1(char *payload_p, uint16_t msgID, uint16_t testVal)
{
    char intBuffer[INT_BUFFER_SIZE];

    strcat(payload_p, JSON_INITIAL_KEY);

    strcat(payload_p, JSON_MSGID_KEY);
    sprintf(intBuffer,"%d", msgID);
    strcat(payload_p, intBuffer);

    strcat(payload_p, JSON_SEPERATOR_KEY);

    strcat(payload_p, JSON_COUNT_KEY);
    sprintf(intBuffer,"%d", testVal);
    strcat(payload_p, intBuffer);

    strcat(payload_p, JSON_FINAL_KEY);
}
void json_stringify_topic2(char *payload_p, uint16_t msgID, uint16_t testVal)
{
    char intBuffer[INT_BUFFER_SIZE];

    strcat(payload_p, JSON_INITIAL_KEY);

    strcat(payload_p, JSON_MSGID_KEY);
    sprintf(intBuffer,"%d", msgID);
    strcat(payload_p, intBuffer);

    strcat(payload_p, JSON_SEPERATOR_KEY);

    strcat(payload_p, JSON_SUM_KEY);
    sprintf(intBuffer,"%d", testVal);
    strcat(payload_p, intBuffer);

    strcat(payload_p, JSON_FINAL_KEY);
}
