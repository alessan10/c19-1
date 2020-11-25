import sys
import time
import telepot
from telepot.loop import MessageLoop

def handle(msg):
    content_type, chat_type, chat_id = telepot.glance(msg)
    print(content_type, chat_type, chat_id)
    print(msg['chat']['id'])

    if content_type == 'text':
        bot.sendMessage(chat_id, msg['text'])

TOKEN = '1349052173:AAEgIwaGT45t-PbOnmx_7o_1XvWuD1wsqPQ'

bot = telepot.Bot(TOKEN)
MessageLoop(bot, handle).run_as_thread()
print ('Listening ...')

# Keep the program running.
while 1:
    time.sleep(10)
