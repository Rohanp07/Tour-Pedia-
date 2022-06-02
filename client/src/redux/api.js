import axios from 'axios';

const API = axios.create({ baseURL: 'http://localhost:5000' });

//passing the user token to the header
//to update the request header with token so that it reaches backend from frontend
API.interceptors.request.use((req) => {
    if (localStorage.getItem('profile')) {

        req.headers.Authorization = `Bearer ${JSON.parse(localStorage.getItem("profile")).token}`;

    }

    return req;
});



export const signIn = (formdata) => API.post("/users/signIn", formdata);
export const signUp = (formdata) => API.post("/users/signUp", formdata);
export const createTour = (tourData) => API.post("/tour", tourData);
export const getTours = () => API.get("/tour");
export const getTour = (id) => API.get(`/tour/${id}`);