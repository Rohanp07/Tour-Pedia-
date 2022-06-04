import { createSlice, createAsyncThunk } from "@reduxjs/toolkit";
import * as api from "../api";

export const createTour = createAsyncThunk(
    "tour/createTour",
    async ({ updatedTourData, navigate, toast }, { rejectWithValue }) => {

        try {
            const response = await api.createTour(updatedTourData);
            toast.success("Tour Created Successfully");
            navigate("/");
            return response.data;

        } catch (err) {

            return rejectWithValue(err.response.data);

        }

    }
);

export const getTours = createAsyncThunk(
    "tour/getTours",

    //we need to provide _ when passing no parameters 
    async (_, { rejectWithValue }) => {

        try {
            const response = await api.getTours();

            return response.data;

        } catch (err) {

            return rejectWithValue(err.response.data);

        }

    }
)

export const getTour = createAsyncThunk(
    "tour/getTour",

    //we need to provide _ when passing no parameters 
    async (id, { rejectWithValue }) => {
        console.log("id is  in slice", id);

        try {
            const response = await api.getTour(id);

            return response.data;

        } catch (err) {

            return rejectWithValue(err.response.data);

        }

    }
)
export const getToursByUser = createAsyncThunk(
    "tour/getToursByUser",

    //we need to provide _ when passing no parameters 
    async (userId, { rejectWithValue }) => {


        try {
            const response = await api.getToursByUser(userId);

            return response.data;

        } catch (err) {

            return rejectWithValue(err.response.data);

        }

    }
)

export const deleteTour = createAsyncThunk(
    "tour/deleteTour",

    //we need to provide _ when passing no parameters 
    async ({ id, toast }, { rejectWithValue }) => {


        try {
            const response = await api.deleteTour(id);
            toast.success("Tour Deleted Successfully");
            return response.data;

        } catch (err) {

            return rejectWithValue(err.response.data);

        }

    }
)

export const updateTour = createAsyncThunk(
    "tour/updateTour",

    //we need to provide _ when passing no parameters 
    async ({ id, updatedTourData, toast, navigate }, { rejectWithValue }) => {


        try {
            const response = await api.updateTour(updatedTourData, id);
            toast.success("Tour Updated Successfully");
            navigate("/");
            return response.data;

        } catch (err) {

            return rejectWithValue(err.response.data);

        }

    }
)




const tourSlice = createSlice({
    name: "tour",
    initialState: {
        tour: {},
        tours: [],
        //the tours only of a particular user 
        userTours: [],

        error: "",
        loading: false
    },

    extraReducers: {
        [createTour.pending]: (state, action) => {
            state.loading = true;
        },
        [createTour.fulfilled]: (state, action) => {
            state.loading = false;
            state.tours = [action.payload];


        },
        [createTour.rejected]: (state, action) => {
            state.loading = false;
            state.error = action.payload;
        },


        [getTours.pending]: (state, action) => {
            state.loading = true;
        },
        [getTours.fulfilled]: (state, action) => {
            state.loading = false;
            state.tours = action.payload;


        },
        [getTours.rejected]: (state, action) => {
            state.loading = false;
            state.error = action.payload.message;
        },
        [getTour.pending]: (state, action) => {
            state.loading = true;
        },
        [getTour.fulfilled]: (state, action) => {
            state.loading = false;
            state.tour = action.payload;


        },
        [getTour.rejected]: (state, action) => {
            state.loading = false;
            state.error = action.payload.message;
        },
        [getToursByUser.pending]: (state, action) => {
            state.loading = true;
        },
        [getToursByUser.fulfilled]: (state, action) => {
            state.loading = false;
            state.userTours = action.payload;


        },
        [getToursByUser.rejected]: (state, action) => {
            state.loading = false;
            state.error = action.payload.message;
        },

        [deleteTour.pending]: (state, action) => {
            state.loading = true;
        },
        [deleteTour.fulfilled]: (state, action) => {
            state.loading = false;
            //imp step we need to update ui 
            //arg will contain tour id 
            console.log("action", action);
            const { arg: { id } } = action.meta;
            if (id) {
                state.userTours = state.userTours.filter(tour => tour._id !== id);
                state.tours = state.tours.filter(tour => tour._id !== id);
            }


        },
        [deleteTour.rejected]: (state, action) => {
            state.loading = false;
            state.error = action.payload.message;
        },
        [updateTour.pending]: (state, action) => {
            state.loading = true;
        },
        [updateTour.fulfilled]: (state, action) => {
            state.loading = false;
            //imp step we need to update ui 
            //arg will contain tour id 
            console.log("action", action);
            const { arg: { id } } = action.meta;
            if (id) {
                state.userTours = state.userTours.map(tour => tour._id === id ? action.payload : tour);
                state.tours = state.tours.map(tour => tour._id === id ? action.payload : tour);
            }







        },
        [updateTour.rejected]: (state, action) => {
            state.loading = false;
            state.error = action.payload.message;
        },



    }
});



export default tourSlice.reducer;