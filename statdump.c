 /*

 Copyright(C) 2005-2014 Simon Howard

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 --

 Functions for presenting the information captured from the statistics
 buffer to a file.

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "d_player.h"
#include "d_mode.h"
#include "m_argv.h"

#include "statdump.h"

#include <riv.h>

extern riv_context riv;

// Array of end-of-level statistics that have been captured.

#define MAX_CAPTURES 32
static wbstartstruct_t captured_stats[MAX_CAPTURES];
static int num_captured_stats = 0;

typedef struct sum_stats {
    int numkills;
    int maxkills;
    int numitems;
    int maxitems;
    int numsecrets;
    int maxsecrets;
    int numlevels;
    int time;
    int partime;
} sum_stats_t;

/* Display statistics for a single player. */

static void PrintPlayerStats(FILE *stream, sum_stats_t *sum, wbstartstruct_t *stats, int player_num)
{
    wbplayerstruct_t *player = &stats->plyr[0];

    /* Kills percentage */
    double kills = stats->maxkills > 0 ? (player->skills * 100.0) / stats->maxkills : 100.0;
    fprintf(stream, "\t\t\"kills\": %.2f,\n"
                    "\t\t\"numkills\": %d,\n"
                    "\t\t\"maxkills\": %d,\n",
                    kills, player->skills, stats->maxkills);
    sum->numkills += player->skills;
    sum->maxkills += stats->maxkills;

    /* Items percentage */
    double items = stats->maxitems > 0 ? (player->sitems * 100.0) / stats->maxitems : 100.0;
    fprintf(stream, "\t\t\"items\": %.2f,\n"
                    "\t\t\"numitems\": %d,\n"
                    "\t\t\"maxitems\": %d,\n",
                    items, player->sitems, stats->maxitems);
    sum->numitems += player->sitems;
    sum->maxitems += stats->maxitems;

    /* Secrets percentage */
    double secret = stats->maxsecret > 0 ? (player->ssecret * 100.0) / stats->maxsecret : 100.0;
    fprintf(stream, "\t\t\"secrets\": %.2f,\n"
                    "\t\t\"numsecrets\": %d,\n"
                    "\t\t\"maxsecrets\": %d,\n",
                    secret, player->ssecret, stats->maxsecret);
    sum->numsecrets += player->ssecret;
    sum->maxsecrets += stats->maxsecret;

}

/* Print details of a statistics buffer to the given file. */
static void PrintStats(FILE *stream, sum_stats_t *sum, wbstartstruct_t *stats)
{
    fprintf(stream, "{\n");
    int episode = stats->epsd;
    int level = stats->last;
    fprintf(stream, "\t\t\"name\": \"E%iM%i\",\n", episode + 1, level + 1);

    int leveltime = stats->plyr[0].stime / TICRATE;
    int partime = stats->partime / TICRATE;

    if (stats->plyr[0].in) {
        PrintPlayerStats(stream, sum, stats, 0);
    }
    fprintf(stream, "\t\t\"time\": %d,\n", leveltime);
    fprintf(stream, "\t\t\"partime\": %d\n", partime);
    sum->time += leveltime;
    sum->partime += partime;

    fprintf(stream, "\t}");
}

void StatCopy(wbstartstruct_t *stats)
{
    if (num_captured_stats < MAX_CAPTURES) {
        /* Replace stats for existing level */
        int to_save_index = -1;
        for (int i = 0; i < num_captured_stats; ++i) {
            if (captured_stats[i].epsd == stats->epsd && captured_stats[i].last == stats->last) {
                to_save_index = i;
                break;
            }
        }
        if (to_save_index == -1) {
            to_save_index = num_captured_stats;
            ++num_captured_stats;
        }
        /* Copy stats */
        memcpy(&captured_stats[to_save_index], stats, sizeof(wbstartstruct_t));
    }
    /* Dump stats */
    StatDump();
}

void StatDump(void)
{
    FILE *stream = fmemopen(riv.inoutbuffer, RIV_MMIOSIZE_INOUTBUFFER, "wb");
    if (!stream) {
        return;
    }
    sum_stats_t sum = {0};
    fprintf(stream, "JSON{\n");
    fprintf(stream, "\t\"levels\": [");
    for (int i = 0; i < num_captured_stats; ++i) {
        if (i != 0) {
            fprintf(stream, ", ");
        }
        PrintStats(stream, &sum, &captured_stats[i]);
    }
    fprintf(stream, "],\n");
    fprintf(stream, "\t\"numlevels\": %d,\n", num_captured_stats);

    /* Kills percentage */
    double kills = sum.maxkills > 0 ? (sum.numkills * 100.0) / sum.maxkills : 100.0;
    fprintf(stream, "\t\"kills\": %.2f,\n"
                    "\t\"numkills\": %d,\n"
                    "\t\"maxkills\": %d,\n",
                    kills, sum.numkills, sum.maxkills);

    /* Items percentage */
    double items = sum.maxitems > 0 ? (sum.numitems * 100.0) / sum.maxitems : 100.0;
    fprintf(stream, "\t\"items\": %.2f,\n"
                    "\t\"numitems\": %d,\n"
                    "\t\"maxitems\": %d,\n",
                    items, sum.numitems, sum.maxitems);

    /* Secrets percentage */
    double secrets = sum.maxsecrets > 0 ? (sum.numsecrets * 100.0) / sum.maxsecrets : 100.0;
    fprintf(stream, "\t\"secrets\": %.2f,\n"
                    "\t\"numsecrets\": %d,\n"
                    "\t\"maxsecrets\": %d,\n",
                    secrets, sum.numsecrets, sum.maxsecrets);

    fprintf(stream, "\t\"time\": %d,\n", sum.time);
    fprintf(stream, "\t\"partime\": %d\n", sum.partime);

    fprintf(stream, "}\n");
    fflush(stream);

    riv.outcard_len = ftell(stream);
    fclose(stream);

    printf("Statistics captured for %i level(s)\n", num_captured_stats);
}
