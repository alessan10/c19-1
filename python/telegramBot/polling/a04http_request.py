import requests
payload = {
	"name":"bau5",
	"chatid": "00000",
	"covid": "negativo"	
}
response = requests.post(url='http://localhost:8081/add', data=payload)
#response = requests.post(url='http://localhost:8081/add',data={'username': user['username'],'chatid': user['id'],'name' : user_data[NAME]}).json()
print("respose: ", response)
