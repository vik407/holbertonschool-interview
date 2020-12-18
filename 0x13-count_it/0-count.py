#!/usr/bin/python3
""" 0. Count it!
"""

from collections import Counter, defaultdict

import re
import requests


def count_words(subreddit, word_list, res=defaultdict(int), after=None):
    """ Looping in subreddit """
    agent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64)\
            AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.97\
            Safari/537.36"
    headers = {"User-Agent": agent}
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    if after:
        url += '?after={}'.format(after)
    try:
        r = requests.get(url, headers=headers, allow_redirects=False).json()
        titles = r.get('data').get('children')
        for t in titles:
            c = Counter(t.get('data').get('title').lower().split(' '))
            for word in word_list:
                if word.lower() in c:
                    res[word.lower()] += c.get(word.lower())
        after = r.get('data').get('after')
        if after:
            return count_words(subreddit, word_list, res, after)
        first_sort = sorted(res.items(), key=lambda x: x[0])
        for k, v in sorted(first_sort, key=lambda x: x[1], reverse=True):
            print('{}: {}'.format(k, v))
    except:
        return
